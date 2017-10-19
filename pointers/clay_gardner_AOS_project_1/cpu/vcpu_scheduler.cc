#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libvirt/libvirt.h>

//HOLDS DATA FOR EACH VIRTUAL CPU
struct virtualPhysicalInfo {
    int domain;
    int vcpu;
    int cpu;
    double cpuTime;
};

//HOLDS THE START AND END TIMES FOR THE PCPU TIMES
struct pCpuTimer {
    double start;
    double finish;
};

//DELAY FOR GIVEN TIME
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main(int argc, char** argv) {

    //ENSURE CORRECT NUMBER OF ARGUMENTS WERE SUPPLIED
    if (argc != 2) {
        fprintf(stderr, "incorrect number of args. Only takes one, you gave %d\nUsage: ./vcpu_scheduler <number of seconds to run>\n",argc);
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
    int numCpus = compInfo.cpus;
    int mapLen = VIR_CPU_MAPLEN(numCpus);
    int cpuNum = -1, i = 0, j, numDomains, c = 0;
    int *activeDomains, ncpus;
    int nparams = 0, min;
    numDomains = virConnectNumOfDomains(conn);
    activeDomains = (int*)malloc( sizeof(int)* numDomains );
    numDomains = virConnectListDomains(conn, activeDomains, numDomains);
    virDomainPtr* domainObjects = (virDomainPtr*)malloc(sizeof(virDomainPtr) * numDomains);
    virDomainInfo* domainInfo = (virDomainInfo*)malloc(sizeof(virDomainInfo) * numDomains);
    virVcpuInfo* vcpuInfo1 = (virVcpuInfo*)malloc(sizeof(virVcpuInfo) * 4);
    virVcpuInfo* vcpuInfo2 = (virVcpuInfo*)malloc(sizeof(virVcpuInfo) * 4);
    unsigned char** cpuMaps = (unsigned char**)malloc(2 * sizeof(char *));
    unsigned long long cpuTime1[numDomains], cpuTime2[numDomains];
    virNodeCPUStats* params = (virNodeCPUStats*)malloc(sizeof(virNodeCPUStats) * nparams);


    //GET ENVIROMENT VARIABLES
    if (virNodeGetCPUStats(conn, cpuNum, NULL, &nparams, 0) == 0 &&
        nparams != 0) {
        if ((params = (virNodeCPUStats*)malloc(sizeof(virNodeCPUStats) * nparams)) == NULL)
            return 1;
        memset(params, 0, sizeof(virNodeCPUStats) * nparams);
        if (virNodeGetCPUStats(conn, cpuNum, params, &nparams, 0))
            return 1;
    }
    virNodeGetCPUStats(conn, cpuNum, params, &nparams, 0);
    virNodeCPUStats* pCpuStats;
    pCpuTimer pCpuTimers[numCpus];
    double totalTimeArray[numCpus];
    pCpuStats = (virNodeCPUStats*)malloc(sizeof(virNodeCPUStats) * nparams);
    memset(pCpuStats, 0, sizeof(virNodeCPUStats) * nparams);
    virNodeGetCPUStats(conn, 0, pCpuStats, &nparams, 0);
    free(params);


    //DECLARE AND MALLOC SPACE FOR VARIABLES THAT USE ENVIROMENT VARIABLES
    unsigned char* map = (unsigned char*)malloc(sizeof(unsigned char*) * mapLen * numCpus);
    virVcpuInfo* vcpu_info;
    int numVirToPhys = numDomains * 4; //the 4 is for 4 vcpus
    virtualPhysicalInfo *virPhys1 = (virtualPhysicalInfo*) malloc(sizeof(virtualPhysicalInfo) * numVirToPhys);
    virtualPhysicalInfo *virPhys2 = (virtualPhysicalInfo*) malloc(sizeof(virtualPhysicalInfo) * numVirToPhys);


    //GRAB DOMAIN OBJECTS AND CPU INFO
    for (i = 0; i < numDomains; i++) {
        domainObjects[i] = virDomainLookupByID(conn,activeDomains[i]);
        virDomainGetInfo(domainObjects[i],&domainInfo[i]);
        memset(map, 0, sizeof(unsigned char *) * mapLen * numCpus);
        VIR_USE_CPU(map, 0);
        vcpu_info = (virVcpuInfo *) malloc(sizeof(virVcpuInfo) * domainInfo[i].nrVirtCpu);
        if (virDomainGetVcpus(domainObjects[i], vcpu_info, domainInfo[i].nrVirtCpu, map, mapLen) < 0) {
            fprintf(stderr, "Cannot check vCPUs for domain %i\n", i);
        }
        for (j = 0; j < domainInfo[i].nrVirtCpu; j++) {
            virPhys1[c].vcpu = virPhys2[c].vcpu = (int) vcpu_info[j].number;
            virPhys1[c].domain = virPhys2[c].vcpu = (int) i;
            c++;
        }
        free(vcpu_info);
    }


    //ONE LOOP FOR EACH SECOND OF THE ARGUMENT PASSED IN
    int f;
    for (f = 0; f < secondsToRun ; f++) {
        c=0;
        //FIRST LOOP TO COLLECT VIRTUAL CPU DATA
        for (i = 0; i < numDomains; i++) {
            memset(map, 0, sizeof(unsigned char *) * mapLen * numCpus);
            VIR_USE_CPU(map, 0);
            vcpu_info = (virVcpuInfo *) malloc(sizeof(virVcpuInfo) * domainInfo[i].nrVirtCpu);
            if (virDomainGetVcpus(domainObjects[i], vcpu_info, domainInfo[i].nrVirtCpu, map, mapLen) < 0) {
                fprintf(stderr, "Cannot check vCPUs for domain %i\n", i);
            }
            for (j = 0; j < domainInfo[i].nrVirtCpu; j++) {
                virPhys1[c].cpu = (int) vcpu_info[j].cpu;
                virPhys1[c].cpuTime = (double) (vcpu_info[j].cpuTime / 1000000000.0);
                c++;
            }
            free(vcpu_info);
        }

        c = 0;

        //FIRST LOOP TO COLLECT PHYSICAL CPU DATA
        for (i = 0; i < numCpus; i++) {
            virNodeGetCPUStats(conn, 0, pCpuStats, &nparams, 0);
            pCpuTimers[i].start = (double) (pCpuStats[0].value + pCpuStats[1].value) / 1000000000.0;
        }


        //DELAY PERIOD ONE SECOND
        delay(1000000);

        //SECOND LOOP TO COLLECT VIRTUAL CPU DATA
        for (i = 0; i < numDomains; i++) {
            if (virDomainGetInfo(domainObjects[i], &domainInfo[i]) < 0) {
                fprintf(stderr, "failed to get the domain information, terminating\n");
                virConnectClose(conn);
                exit(1);
            }
            memset(map, 0, sizeof(unsigned char *) * mapLen * numCpus);
            VIR_USE_CPU(map, 0);
            vcpu_info = (virVcpuInfo *) malloc(sizeof(virVcpuInfo) * domainInfo[i].nrVirtCpu);
            if (virDomainGetVcpus(domainObjects[i], vcpu_info, domainInfo[i].nrVirtCpu, map, mapLen) < 0) {
                fprintf(stderr, "Cannot check vCPUs for domain %i\n", i);
            }
            for (j = 0; j < domainInfo[i].nrVirtCpu; j++) {
                virPhys2[c].cpu = (int) vcpu_info[j].cpu;
                virPhys2[c].cpuTime = (double) (vcpu_info[j].cpuTime / 1000000000.0);
                c++;

            }
            free(vcpu_info);

        }


        //SECOND LOOP TO COLLECT PHYSICAL CPU DATA
        for (i = 0; i < numCpus; i++) {
            virNodeGetCPUStats(conn, 0, pCpuStats, &nparams, 0);
            pCpuTimers[i].finish = (double) (pCpuStats[0].value + pCpuStats[1].value) / 1000000000.0;
        }


        //SETUP ARRAY THAT WILL BE USED FOR SORTING
        int indexArr[numVirToPhys];
        for (i = 0; i < numVirToPhys; i++) {
            indexArr[i] = i;
            c = indexArr[i];
        }

        //SORT THE VCPUS BASED ON HOW MUCH PCPU TIME THEY HAVE EACH USED
        int tmp;
        double key, k;
        for (i = 1; i < numVirToPhys; i++) {
            j = i - 1;
            k = i;
            key = virPhys2[indexArr[i]].cpuTime - virPhys1[indexArr[i]].cpuTime;
            while (j >= 0 && key > virPhys2[indexArr[j]].cpuTime - virPhys1[indexArr[j]].cpuTime) {
                indexArr[j + 1] = indexArr[j];
                j--;
            }
            indexArr[j + 1] = k;
        }

        //DECIDE WHICH PCPU TO PIN EACH VCPU
        for (i = 0; i < numVirToPhys; i++) {
            c = indexArr[i];
            min = 0;
            //FIND THE PCPU WITH SMALLEST LOAD
            for (j = 1; j < numCpus; j++) {
                if (totalTimeArray[j] < totalTimeArray[min]) {
                    min = j;
                }
            }
            //ADD TO ARRAY THAT STORES HOW MUCH PROCESSOR TIME EACH PCPU HAS USED
            totalTimeArray[min] = totalTimeArray[min] + virPhys2[c].cpuTime - virPhys1[c].cpuTime;
            //IS THE VCPU ALREADY PINNED TO THIS VCPU?
            if (min != virPhys1[c].cpu) {
                map = (unsigned char*)calloc(VIR_CPU_MAPLEN(numCpus), sizeof(unsigned char));
                VIR_USE_CPU(map, min);
                //PIN CURRENT VCPU TO THE CURRENT CPU WITH SMALLEST LOAD
                printf("vCPU %i on domain %i was pinned to pCPU %i.\n",virPhys1[c].vcpu,virPhys1[c].domain,min);
                virDomainPinVcpuFlags(domainObjects[virPhys1[c].domain],virPhys1[c].vcpu,map,mapLen,1);
            }

        }
        printf("pCPU usage after %i second(s):\n",f+1);
        for (i = 0; i < numCpus; i++) {
            printf("pCPU %i| %f seconds\n",i,pCpuTimers[i].finish -pCpuTimers[i].start );
        }
        printf("\n");


        //SET THE VCPU TIMER BACK TO ZERO
        for(j = 0; j < numCpus; j++) {
            totalTimeArray[j] = 0.0;
        }

    }

    //FREE MEMORY AND CLOSE CONNECTION
    free(activeDomains);
    free(domainObjects);
    free(domainInfo);
    free(map);
    virConnectClose(conn);




    return 0;
}
