#include <stdio.h>
#include "sqrt.h"

int main(){
	int num;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			num = 16 * i + j;
			printf("%2d, ", i_sqrt(num));
		
		}
		printf("\n");
	}

	return 0;
}

