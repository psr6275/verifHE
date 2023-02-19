#ifndef MPCITH_H
#define MPCITH_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define RIGHTROTATE(x,n) (((x) >> (n)) | ((x) << (32-(n))))
#define GETBIT(x, i) (((x) >> (i)) & 0x01)
#define SETBIT(x, i, b)   x= (b)&1 ? (x)|(1 << (i)) : (x)&(~(1 << (i)))

#define ySize 928 // value of *countY after the commit phase;

typedef struct {
	unsigned char x[64];
	uint32_t y[ySize];
} View;

class Commit {
public:
    Commit(View *views[3]);
    void mpc_ADD(uint32_t x[3], uint32_t y[3], uint32_t z[3], unsigned char *randomness[3], int* randCount, int* countY);
}
inline uint32_t bits2int(unsigned char* input) {
	uint32_t out = 0;
	for(int j=0; j<32; j++) {
		out += ((uint32_t)input[32 - j -1]) << j;
	}
	return out;
}

inline uint32_t getRandom32(unsigned char randomness[3552], int randCount) {
	uint32_t ret;
	memcpy(&ret, &randomness[randCount], 4);
	return ret;
}

inline uint32_t getRandom1(unsigned char randomness[3552], int randCount) {
	uint32_t ret;
	memcpy(&ret, &randomness[randCount], 1);
	return (ret >> 1) & 1;
}

#endif