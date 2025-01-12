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

int main(){
    uint32_t div, mod;
    for(uint32_t i = 0; i < INT32_MAX; i++){
        divmod_10(i, &div, &mod);

        if(div != i / 10)
            printf("Div discrepancy at: %d, div: %d\n", i, div);
        
        if(mod != i % 10)
            printf("Mod discrepancy at: %d, mod: %d\n", i, mod);
    }
    
    
}