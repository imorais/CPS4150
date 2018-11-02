// To get optimization level 1 in assembly code, use the following command:
// gcc -m32 ex1.c -S -O1 --> in the optimization part, -O1, it is a capital o, not a zero.

int accum = 0;

int sum(int x, int y){

	int t = x + y;
	accum += t;
	return t;	

}
