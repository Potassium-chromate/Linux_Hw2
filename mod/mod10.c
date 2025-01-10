#include <stdint.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    for (int n = 0; n <= INT_MAX; n++) {
        if(n % 100 == 0)
            printf("%d cases is pass\n", n);
        //printf("Iteration: %d\n", n);
        unsigned d2, d1, d0, q, r;

        d0 = q & 0b1;
        d1 = q & 0b11;
        d2 = q & 0b111;
        q = ((((n >> 3) + (n >> 1) + n) << 3) + d0 + d2) >> 7;  // Initialize q
        printf("%d * 13 = %d\n", n, ((((n >> 3) + (n >> 1) + n) << 3) + d0 + d1 + d2));
        //printf("q: %d\n", q);
        r = n - (((q << 2) + q) << 1);  // Calculate r
        //printf("q: %d r: %d\n", q, r);
        if (r != n % 10){
            printf("Error happend at %d\n", n);
            printf("Ground truth: %d, Calculate result: %d\n", n % 10, r);
            return 0;
        }

            
    }

    printf("All testcases pass!");

    return 0;
}
