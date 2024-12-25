#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "sqrt.h"
#include "fast_isqrt.h"

void benchmark_sqrt(int benchmark_term){
	clock_t start, end;
    double time_int_sqrt = 0.0, time_i_sqrt = 0.0;

    for (int i = 0; i < benchmark_term; i++) {   
        start = clock();
        int appro = fast_i_sqrt(i);
        end = clock();
        time_int_sqrt += (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        int gt = i_sqrt(i);
        end = clock();
        time_i_sqrt += (double)(end - start) / CLOCKS_PER_SEC;

        if (appro != gt) {
            printf("Discrepancy at i = %d\n", i);
            printf("int_sqrt result: %d\n", appro);
            printf("i_sqrt result: %d\n", gt);
            break;
        }
    }
	
	printf("Benchmark term: %d\n", benchmark_term);
    printf("Total time taken by fast_i_sqrt: %.2f seconds\n", time_int_sqrt);
    printf("Total time taken by i_sqrt: %.2f seconds\n", time_i_sqrt);
}

void verify_sqrt(int max_check) {
    int discrepancies = 0;

    for (int i = 0; i < max_check; i++) {
        int test = fast_i_sqrt(i);
        int ground_truth = i_sqrt(i);

        if (test != ground_truth) {
            printf("Discrepancy at: %d\n", i);
            printf("fast_i_sqrt result: %d\n", test);
            printf("i_sqrt result: %d\n", ground_truth);
            discrepancies++;

            if (discrepancies >= 10) {  // Stop after 10 discrepancies
                printf("Too many discrepancies. Stopping early.\n");
                return;
            }
        }
    }

    if (discrepancies == 0) {
        printf("All values verified up to %d.\n", max_check - 1);
    }
}

int main()
{	
	int appro;
	for(int i = 0; i < 1000000; i++){
		appro = i_sqrt(i);
	}

    return 0;
}

