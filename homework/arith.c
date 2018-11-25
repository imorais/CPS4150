// To compile this code into assembly with optimization leve1 01, type the following command:
// gcc -m32 arith.c -S -O1  --> -m32 means compile in a 32 bit machine

int arith(int x, int y, int z)

{

	int t1 = x+z;
	int t2 = y-t1;
	int t3 = y*2;
	int t4 = z + 20;
	int t5 = t4 - t3;
	int rval = t5 - t2;
	return rval;

}

