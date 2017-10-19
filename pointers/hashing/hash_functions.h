#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>

unsigned addHash(void *key, unsigned len);

unsigned XORHash(void *key, unsigned len);

unsigned ROTHash(void *key, unsigned len);

unsigned DJBHash(void *key, unsigned len);

unsigned modifiedDJBHash(void *key, unsigned len);

unsigned shiftAddXORHash(void *key, unsigned len);

unsigned FNVHash(void *key, unsigned len);

unsigned oneAtATimeHash(void *key, unsigned len);

unsigned ELFHash(void *key, unsigned len);

unsigned jenkinsHash(unsigned char *k, unsigned length, unsigned initval);

unsigned CMGHash(void *key, unsigned len);