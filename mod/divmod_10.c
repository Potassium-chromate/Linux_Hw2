#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#define CCCC 3
#define DDDD 1
void divmod_10(uint32_t in, uint32_t *div, uint32_t *mod)
{   
    uint32_t x = (in | 1) - (in >> 2);          //0.75 in
    uint32_t q = (x >> 4) + x;                  //0.7968 in
    x = q;                              
    q = (q >> 8) + x;                           //0.799 in
    q = (q >> 8) + x;                           //0.803 in
    q = (q >> 8) + x;                           //0.806 in
    q = (q >> 8) + x;                           //0.809 in

    *div = (q >> CCCC);                         //div = 0.1011 in
    //*mod = in - ((q & ~0x7) + (*div << DDDD));  //mod = in - (0.8 in + 0.2 in)
    *mod = in - ((*div << CCCC) + (*div << DDDD));
}

void DivMod_10(uint32_t in, uint32_t *div, uint32_t *mod)
{   
    *div = in / 10;
    *mod = in % 10;
}

int main(){
    uint32_t div, mod;
    //divmod_10(100544, &div, &mod);
    DivMod_10(100544, &div, &mod);
}
