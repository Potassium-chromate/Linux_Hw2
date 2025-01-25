#include <stdio.h>

void print_bit(unsigned n);

unsigned popcount_naive(unsigned v)
{
    unsigned n = 0; // Initialize count to 0
    while (v)
    {
        print_bit(v);
        print_bit(v - 1);
        v &= (v - 1);
        n = -(~n);
    }
    return n;
}

unsigned popcount_branchless(unsigned v)
{
    unsigned n;
    n = (v >> 1) & 0x77777777;
    printf("n: ");
    print_bit(n);
    v -= n;
    printf("v: ");
    print_bit(v);
    n = (n >> 1) & 0x77777777;
    printf("n: ");
    print_bit(n);
    v -= n;
    printf("v: ");
    print_bit(v);
    n = (n >> 1) & 0x77777777;
    printf("n: ");
    print_bit(n);
    v -= n;
    printf("v: ");
    print_bit(v);
    v = (v + (v >> 4)) & 0x0F0F0F0F;
    printf("v: ");
    print_bit(v);
    v *= 0x01010101;                                     
	printf("v: ");
    print_bit(v);
    return v >> 24;
}

void print_bit(unsigned n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1); 
        if (i % 4 == 0 && i > 0)    
            printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned v = 0xFEA605C;
    //unsigned result = popcount_naive(v);
    unsigned result = popcount_branchless(v);
    printf("Population count: %u\n", result); // Print the result
    return 0;
}

