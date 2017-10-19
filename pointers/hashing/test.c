 #include "hash_functions.c"
#include "test.h"


void zeroMatrix(unsigned *array, unsigned length) {
	int i;
	for (i = 0; i < length ; i++) {
		array[i]=0;
	}
}

unsigned long factorial(unsigned n) {
	unsigned long f = 1;
	int i;
	for (i =1; i <=n; i++) {
		f = f * i;
	}
	return f;
}

//For calculating the number of collisions
unsigned long choose(unsigned n, unsigned k) {
	return factorial(n)/(factorial(n-k)*factorial(k));
}

char *randstring(size_t length) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));
        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }
    return randomString;
}

void fillArray(char **keys, unsigned length) {
    int i;
    for(i=0; i < length; i++) {
        keys[i] = (char *)randstring(1000);
    }
}

unsigned long countCollisions(unsigned len, unsigned *indices, unsigned max)
{

	unsigned totals[len];
	zeroMatrix(&totals[0],len);
	int i;

	for(i=0; i <len; i++) {
		totals[indices[i]]++;
	}
	unsigned long collisions=0;
	for (i=0; i < len; i++) {
		if (totals[i]>0) {
			
			if (i >1) {
				collisions+=totals[i]*choose(i,2);
				//printf("Collisions: %lu Index value: %lu\n",collisions,totals[i]*choose(i,2));
			} 		
		}
	}
	//printf("Collisions: %lu Keys: %u\n",collisions,len);
	return collisions;
}




void distribution(unsigned l, unsigned *indices,double *avg, double *var) {
    unsigned dis[l];
    zeroMatrix(&dis[0],l);
    unsigned i;
    double total=0;
    for(i=0; i < l; i++) {
        total+=(double)indices[i]*(i+1);
        dis[indices[i]]++;
    }
    *avg += total/l;
    //printf("Average: %f \n",*avg);
    //sqrt(sum(x-xbar)^s)


}


unsigned testHashFunction(unsigned l,float loadfactor,double *avg, double *var,unsigned (*FuncPtr)(void *,unsigned)) {
	unsigned i,h,max=0;
	if (loadfactor<1) {
		loadfactor=1;
	}
	unsigned k = l*loadfactor;
	char *strings[l];
	unsigned histogram[k];
	zeroMatrix(&histogram[0],k);
	fillArray(&strings[0],l);
	for(i=0;i<l;i++){
		h  = (*FuncPtr)(strings[i],10);
		histogram[h%k]++;
		if(histogram[h%k]>max) {
			max=histogram[h%k];
		}
	} 
	//printf("Load factor: %i ",loadfactor);
    distribution(k,&histogram[0],avg,var);
	return countCollisions(k,&histogram[0],max);



}



double test(int keys, float loadfactor,unsigned (*FuncPtr)(void *,unsigned)) {
    //number of trials
    double trials = 10;
    double sum = 0, avg=0, var=0;
	int i;
	for(i = 0; i<trials; i++) {
		sum+=testHashFunction(keys,loadfactor,&avg,&var,(*FuncPtr));
	}

    //printf("Average: %3.2f Want: %3.2f ",avg/trials,((double)keys*loadfactor)/2.);
    return sum/trials;
}

int main() {
	
	int i= 0;
    float j;
    int g;
    double min;
    double t;
    int minIndex;
    const char *names[10];
    typedef unsigned (*FUNCTIONPOINTER)(void *, unsigned);
    FUNCTIONPOINTER fpa[10];
    names[0] = "Adding"; fpa[0]=addHash;
    names[1] = "XOR"; fpa[1]=XORHash;
    names[2] = "ROT"; fpa[2]=ROTHash;
    names[3] = "Daniel J Bernstein"; fpa[3]=DJBHash;
    names[4] = "Modified Daniel J Bernstein"; fpa[4]=modifiedDJBHash;
    names[5] = "Shift-Add-XOR"; fpa[5]=shiftAddXORHash; 
    names[6] = "FNV"; fpa[6]=FNVHash;
    names[7] = "One At A Time"; fpa[7]=oneAtATimeHash;
    names[8] = "ELF"; fpa[8]=ELFHash;
    names[9] = "Clay Gardner Hash"; fpa[9]=CMGHash;
    unsigned count[10];
    zeroMatrix(&count[0],10);
    
    for(i=25; i < 1500; i*=2) {
        for (j=1;j<=5;j+=.2) {
            min = DBL_MAX;
            for (g=0;g<10;g++) {
                t=test(i,j,fpa[g]);
                //printf("%s: %0.1f\n",names[g],t);
                if (t<min) {
                    min = t;
                    minIndex=g;
                }
            }
            count[minIndex]++;
            printf("Keys: %i Load Factor: %2.1f Function: %s Value: %3.1f\n",i,j,names[minIndex],min );
        }
    }
    for(i=0; i < 10; i++) {
        printf("%s:  %i \n",names[i],count[i]);
    }
	
	return 0;
}