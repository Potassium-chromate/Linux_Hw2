# include "mod_5.h"
# include "mod_9.h"
# include <stdio.h>
# include <limits.h>

int main(){
	//Testify function mod5
	for(int i = 0; i < INT_MAX; i++){
		int temp = mod5(i);
		if (temp != (i % 5)){
			printf("Discrepancy happened at %d\n",i);
			printf("%d mod 5 = %d\n", i, temp);
			return 0;
		}
	} 
	
	//Testify function mod9
	for(int i = 0; i < INT_MAX; i++){
		int temp = mod9(i);
		if (temp != (i % 9)){
			printf("Discrepancy happened at %d\n",i);
			printf("%d mod 9 = %d\n", i, temp);
			return 0;
		}
	}
	
	printf("All testcaes are passed!\n");
	return 0;
}
