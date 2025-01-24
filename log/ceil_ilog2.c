#include <stdio.h>
#include <stdint.h>
#include <math.h>


uint32_t ceil_ilog2(uint32_t x)
{
    uint32_t r, shift;
   	x += (x == 0);
	uint32_t temp = x;
	x--;
	// If x > 0xFFFF, then shift right 16 bits
	r = (x > 0xFFFF) << 4;
	x >>= r;	
	shift = (x > 0xFF) << 3;
    x >>= shift;   
    r |= shift; 
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    
    return (r | shift | x > 1) + (temp > 1);       
}


uint32_t ilog2(uint32_t i)
{	
	int oringin = i;
    int result = 0;
    if (i > 0xFFFF){
    	i >>= 16;
    	result += 16;
    }
    if (i > 0xFF){
    	i >>= 8;
    	result += 8;
    }
    if (i > 0xF){
    	i >>= 4;
    	result += 4;
    }
    if (i > 0x3){
    	i >>= 2;
    	result += 2;
    }
    if (i > 0x1){
    	i >>= 1;
    	result += 1;
    }
    
    result += (i - 1);
    
    return result + (oringin > (1 << result));
}


int main(){
	
	for (int i = 0; i < 1000000; i++){
		
		int gt = ilog2(i);
		int result = ceil_ilog2(i);
		
		if (gt != result){
			printf("----i: %d----\n", i);
			printf("gt: %d\n", gt);
			printf("result: %d\n", result);
		}
	}
	return 0;
}
