#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>
//#include "hash_functions.c"

void zeroMatrix(unsigned *array, unsigned length);

unsigned long factorial(unsigned n);

unsigned long choose(unsigned n, unsigned k);

char *randstring(size_t length);

void fillArray(char **keys, unsigned length);

unsigned long countCollisions(unsigned len, unsigned *indices, unsigned max);

void distribution(unsigned l, unsigned *indices,double *avg, double *var);

unsigned testHashFunction(unsigned l,float loadfactor,double *avg, double *var,unsigned (*FuncPtr)(void *,unsigned));

double test(int keys, float loadfactor,unsigned (*FuncPtr)(void *,unsigned));