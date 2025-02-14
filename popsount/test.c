#include <stdio.h>
#include <limits.h>
unsigned popcount(unsigned v)
{
    unsigned n;
    n = (v >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;
    v = (v + (v >> 4)) & 0x0F0F0F0F;
    v *= 0x01010101;                                     
    return v >> 24;
}

unsigned mod_3_v1(unsigned v){
    //v = (popcount(v & 0x55555555) + 39) - popcount(v & 0xAAAAAAAA);
    v = popcount(v ^ 0xAAAAAAAA) + 23;
    //v: 57 ~ 13 
    //v = popcount(v & 0x55555555) - popcount(v & 0xAAAAAAAA);
    v = popcount(v ^ 0x2A) - 3;
    return v + ((v >> 30) & 3);
}

unsigned mod_3_v2(unsigned n){
    int table[14] ={0, 1, 2, 0, 1, 2,
                    0, 1, 2, 0, 1, 2,
                    0, 1};
    n = (n >> 16) + (n & 0xFFFF);
    n = (n >> 8) + (n & 0xFF);
    n = (n >> 4) + (n & 0xF);
    n = (n >> 2) + (n & 0x3);
    return table[n];
}

int main(){
    int temp;
    for(int i = 0; i < 100000; i++){
   		temp = mod_3_v2(i);
    }
    return 0;
}
