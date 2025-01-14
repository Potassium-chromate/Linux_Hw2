int mod5(int n){
	int table[24] = {0,1,2,3,4,
			 0,1,2,3,4,
			 0,1,2,3,4,
			 0,1,2,3,4,
			 0,1,2,3};
			 
	n = (n >> 16) + (n & 0xFFFF);
	n = (n >> 8) + (n & 0x00FF);
	n = (n >> 4) + (n & 0x000F);
	
	int r = n & 0x7;
	n = n >> 3;

	//3 * n + r
	return table[(n << 1) + n + r];
}
