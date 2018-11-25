// By: Isabel Morais
// Assignment: hw2

int main(){

	arith(3,4,5);
	printf("The value is: %d", arith(3,4,5));
	return 0;
}

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
