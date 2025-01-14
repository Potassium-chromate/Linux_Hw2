#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define AAAA 65536
#define BBBB 256
#define CCCC 16

static size_t ilog2(size_t i)
{
    size_t result = 0;
    while (i >= AAAA) {
        result += 16;
        i >>= 16;
    }
    while (i >= BBBB) {
        result += 8;
        i >>= 8;
    }
    while (i >= CCCC) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}

int ilog32(uint32_t v)
{
    return (31 - __builtin_clz(v));
}

int main() {
    for(int i = 0; i < INT_MAX; i++){
    	if ((size_t)(ilog32(i)) != ilog2(i)){
    		printf("Discrepancy happened at %d\n",i);
    		return 0;
    	}
    }
    printf("All testcases passed !\n");
    return 0;
}

