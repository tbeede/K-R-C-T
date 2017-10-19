Various hashing functions pulled from the internet and tested against my own (Clay Gardner's) hashing function. The testing algorithm works by giving a certain number of keys, a load factor, and then comparing the different algorithms for how many collisions they produce. At the end of test_run.txt you can see the sums of which algorithms were the best on average for a certain trail (each trial had a number of keys, a load balance, and each algorithm was run ten times and the collisions were averaged).


This project was done to learn more about C and hashing functions in general. Concepts learned about:

* Hashing(avalanche, distribution)  
* Function pointers  
* Working with arrays of functions pointers  
* Creating a string of random characters  

My hashing function:

unsigned CMGHash(void *key, unsigned len)  
{  
	unsigned char *p = key;  
    unsigned long long h = 49999;  
    int i;  
    for (i = 0; i < len; i++)  
    {  
        h = h * p[i] ^ 299993 * p[i];  
        h+=(h>>10);   
        h^=(h<<3);  
        h+=(h>>6);  
    }  
    return h;  
}