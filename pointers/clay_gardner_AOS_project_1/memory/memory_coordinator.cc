#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libvirt/libvirt.h"
#include "libvirt/libvirt-host.h"

//DELAY FOR GIVEN TIME
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//HOLDS ALL DATA NEEDED FOR EACH DOMAIN
struct domainMemoryData {
    int domain;
    unsigned long maxMemory;
    unsigned long minMemory;
    unsigned long long balloon;
    unsigned long long available;
    unsigned long long unused;
    double percentage;
    unsigned long long need;
    unsigned long long give;
    unsigned long long transfer;
};

int main(int argc, char** argv) {

    //ENSURE CORRECT NUMBER OF ARGUMENTS WERE SUPPLIED
    if (argc != 2) {
        fprintf(stderr, "incorrect number of args. Only takes one, you gave %d\nUsage: ./memory_coordinator <number of seconds to run>\n",argc);
        exit(1);
    }
    int secondsToRun = atoi(argv[1]);

    //INITIALIZE CONNECTION
    virConnectPtr conn;
    conn = virConnectOpen("qemu:///system");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return 1;
    }

    //DECLARE VARIABLES AND MALLOC SPACE
    virNodeInfo compInfo;
    virNodeGetInfo(conn,&compInfo);
    int i, j, f, k;
    int numDomains, status;
    int *activeDomains;
    unsigned long temp;
    virTypedParameter params;
    numDomains = virConnectNumOfDomains(conn);
    activeDomains = (int*)malloc( sizeof(int)* numDomains );
    numDomains = virConnectListDomains(conn, activeDomains, numDomains);
    virDomainPtr* domainObjects = (virDomainPtr*)malloc(sizeof(virDomainPtr) * numDomains);
    virDomainInfo* domainInfo = (virDomainInfo*)malloc(sizeof(virDomainInfo) * numDomains);
    domainMemoryData* memData = (domainMemoryData*)malloc(sizeof(domainMemoryData) * numDomains);

    //GET ALL THE DOMAINS AND SET UP THE MEMORY COLLECTION
    int time_period = 1;
    int nr_stats = 10;
    unsigned long long totalMem = 0, availableMem = 0;
    int indexArr[numDomains];
    double key;
    int percentages[4];
    for(i = 0; i <numDomains; i++) {
        indexArr[i] = i;
    }

    //SETUP DOMAINS
    for (i = 0 ; i < numDomains ; i++) {
        domainObjects[i] = virDomainLookupByID(conn, activeDomains[i]);
        virDomainSetMemoryStatsPeriod(domainObjects[i], time_period, VIR_DOMAIN_AFFECT_LIVE);
        memData[i].maxMemory = virDomainGetMaxMemory(domainObjects[i]);
        memData[i].domain = i;
        totalMem = totalMem + memData[i].maxMemory;
    }
    virDomainMemoryStatStruct* stats = (virDomainMemoryStatStruct*)malloc(sizeof (virDomainMemoryStatStruct) * nr_stats);


    //THESE ARE THE THREE PERCENTAGES THAT DECIDE WHO GIVES AND WHO TAKES MEMORY
    double one = .50, two = .70, three = .90;


    //ONE LOOP FOR EACH HALF SECOND OF THE ARGUMENT PASSED IN
    for (f = 0; f < secondsToRun*2; f++) {
        delay(500000);


        //COLLECT STATISTICS ON EACH DOMAIN
        for (i = 0; i < numDomains; i++) {
            if (virDomainGetInfo(domainObjects[i], &domainInfo[i]) < 0) {
                fprintf(stderr, "failed to get the domain information, terminating\n");
                virConnectClose(conn);
                exit(1);
            }
            status = virDomainMemoryStats(domainObjects[i], stats, nr_stats, 0);
            for (j = 0; j < nr_stats; j++) {
                if (stats[j].tag == VIR_DOMAIN_MEMORY_STAT_UNUSED) {
                    memData[i].unused = stats[j].val;
                } else if (stats[j].tag == VIR_DOMAIN_MEMORY_STAT_AVAILABLE) {
                    memData[i].available = stats[j].val;
                } else if (stats[j].tag == VIR_DOMAIN_MEMORY_STAT_ACTUAL_BALLOON) {
                    memData[i].balloon = stats[j].val;
                }
            }
            memData[i].percentage = (double)( memData[i].available - memData[i].unused) /((double) memData[i].available);
            memData[i].minMemory = memData[i].maxMemory/4;
            memData[i].transfer = 0;
            virDomainSetMemoryFlags(domainObjects[i],(long)memData[i].balloon,VIR_DOMAIN_AFFECT_LIVE);
        }

        //SORT THE DOMAINS IN ORDER OF MEMORY USEAGE
        for (i = 1; i < numDomains; i++) {
            j = i - 1;
            k = i;
            key = memData[i].percentage;
            while (j >= 0 && key > memData[j].percentage ) {

                indexArr[j + 1] = indexArr[j];
                j--;
            }
            indexArr[j + 1] = k;
        }


        //HOW MUCH MEMORY DO YOU NEED OR CAN YOU GIVE WITHOUT GOING ABOVE OR BELOW IT'S MINIMUM OR MAXIMUM MEMORY
        for (i = 0; i < numDomains; i++) {
            if (memData[indexArr[i]].percentage < one) {
                percentages[0]++;
                temp = memData[indexArr[i]].balloon/4;
                if (temp * 3 >= memData[indexArr[i]].minMemory) {
                    memData[indexArr[i]].give = temp;
                }
            } else if(memData[indexArr[i]].percentage < two) {
                percentages[1]++;
                temp = memData[indexArr[i]].balloon/8;
                if (temp * 7 >= memData[indexArr[i]].minMemory) {
                    memData[indexArr[i]].give = temp;
                }
            } else if(memData[indexArr[i]].percentage < three) {
                percentages[1]++;
                temp = memData[indexArr[i]].balloon/16;
                if (temp * 17 <= memData[indexArr[i]].maxMemory) {
                    memData[indexArr[i]].need = temp;
                }
            } else {
                percentages[3]++;
                temp = memData[indexArr[i]].balloon/8;
                if (temp * 9 <= memData[indexArr[i]].maxMemory) {
                    memData[indexArr[i]].need = temp;
                }
            }
        }

        //SEE HOW MUCH MEMORY YOU CAN EXCHANGE BETWEEN DOMAINS
        for (i = 0; i < numDomains-1; i++) {
            if (memData[indexArr[i]].percentage >= three && memData[indexArr[i]].need > 0) {
                for (j = i+1; j < numDomains; j++) {
                    if (memData[indexArr[j]].give > 0) {
                        if (memData[indexArr[j]].give <= memData[indexArr[i]].need) {
                            memData[indexArr[i]].transfer = memData[indexArr[i]].transfer + memData[indexArr[j]].give;
                            memData[indexArr[j]].transfer = memData[indexArr[j]].transfer + memData[indexArr[j]].give;
                            memData[indexArr[j]].give = 0;
                            memData[indexArr[i]].need = memData[indexArr[i]].need - memData[indexArr[j]].give;
                        } else if (memData[indexArr[j]].give > memData[indexArr[i]].need) {
                            memData[indexArr[i]].transfer = memData[indexArr[i]].transfer + memData[indexArr[i]].need;
                            memData[indexArr[j]].transfer = memData[indexArr[j]].transfer + memData[indexArr[i]].need;
                            memData[indexArr[j]].give = memData[indexArr[j]].give - memData[indexArr[i]].need;
                            memData[indexArr[i]].need = 0;
                        }
                    }
                }
            } else if (memData[indexArr[i]].percentage >= two && memData[indexArr[i]].need > 0) {
                for (j = i+1; j < numDomains; j++) {
                    if (memData[indexArr[j]].give > 0) {
                        if (memData[indexArr[j]].give <= memData[indexArr[i]].need) {
                            memData[indexArr[i]].transfer = memData[indexArr[i]].transfer + memData[indexArr[j]].give;
                            memData[indexArr[j]].transfer = memData[indexArr[j]].transfer + memData[indexArr[j]].give;
                            memData[indexArr[j]].give = 0;
                            memData[indexArr[i]].need = memData[indexArr[i]].need - memData[indexArr[j]].give;
                        } else if (memData[indexArr[j]].give > memData[indexArr[i]].need) {
                            memData[indexArr[i]].transfer = memData[indexArr[i]].transfer + memData[indexArr[i]].need;
                            memData[indexArr[j]].transfer = memData[indexArr[j]].transfer + memData[indexArr[i]].need;
                            memData[indexArr[j]].give = memData[indexArr[j]].give - memData[indexArr[i]].need;
                            memData[indexArr[i]].need = 0;
                        }
                    }
                }
            }
        }

        printf("\nPercentage update:\n");
        for (j = 0; j < numDomains; j++) {
            i = indexArr[numDomains - j - 1];
            printf("Domain %i is using %0.2f of its available memory.\n",i,memData[i].percentage);
        }

        //TRANSFER OF MEMORY BETWEEN DOMAINS
        for (j = 0; j < numDomains; j++) {
            i = indexArr[numDomains - j -1];
            if (memData[i].transfer > 0 && memData[i].percentage < two) {
                printf("Domain %i's memory usage is at %0.2f%% so it is giving up %llu bytes and balloon is shrinking from %llu bytes",i,memData[i].percentage,memData[i].transfer,memData[i].balloon);
                memData[i].balloon = memData[i].balloon - memData[i].transfer;
                printf(" to %llu bytes.\n",memData[i].balloon);
                virDomainSetMemoryFlags(domainObjects[i],memData[i].balloon,VIR_DOMAIN_AFFECT_LIVE);
            } else if (memData[i].transfer > 0 && memData[i].percentage >= two) {
                printf("Domain %i's memory usage is at %0.2f%% so it is taking %llu bytes and balloon is inflating from %llu bytes",i,memData[i].percentage,memData[i].transfer,memData[i].balloon);
                memData[i].balloon = memData[i].balloon + memData[i].transfer;
                printf(" to: %llu bytes.\n",memData[i].balloon);
                virDomainSetMemoryFlags(domainObjects[i],memData[i].balloon,VIR_DOMAIN_AFFECT_LIVE);
            }
            memData[i].need = 0;
            memData[i].give = 0;
            memData[i].transfer = 0;
        }

        //CLEAR VALUES
        for (i =0; i < 4; i++) {
            percentages[i]=0;
        }
        for(i = 0; i <numDomains; i++) {
            indexArr[i] = i;
        }
        availableMem = 0;


    }


    //FREE MEMORY AND CLOSE CONNECTION
    free(activeDomains);
    free(domainObjects);
    free(domainInfo);
    free(memData);
    free(stats);
    virConnectClose(conn);

    return 0;
}

