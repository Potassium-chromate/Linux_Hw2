#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#define CCCC 3

/*
in - (in / 9 * 9)
*/
void divmod_9(uint32_t in, uint32_t *div, uint32_t *mod)
{   
    uint32_t q, r;
    uint32_t n = in + (in >> 31 & 8);
    q = (n >> 1) + (n >> 2) + (n >> 3);     //0.875n
    q = q + (q >> 6);                       //
    q = q + (q >> 12) + (q >> 24);
    q = q >> 3;
    r = n - q * 9;
    //(*div) = q + ((r + 7) >> 4);
    //(*mod) = in - ((*div << 3) + *div);
    (*div) = q;
    (*mod) = r;
}

int main(){
    uint32_t div, mod;
    for(uint32_t i = 0; i < 20; i++){
        divmod_9(i, &div, &mod);

        if(div != i / 9)
            printf("Div discrepancy at: %d, div: %d\n", i, div);
        
        if(mod != i % 9){
            printf("Mod discrepancy at: %d, mod: %d\n", i, mod);
            //return 0;
        }
    }
    
    return 0;
}