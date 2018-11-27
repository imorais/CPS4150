// Program name: pSize.c
// Program shows difference between the size of pointers to a string and an array of characters

#include<stdio.h>

struct testing {
   int id;
   char fName[10];
   char lName[10];
   char bDay[3];
   char bMonth[3];
   char bYear[5];
};

int main() {

  struct testing t1 = {12345, "John", "Smith", "06", "07", "1998"};

  char x[] = "nn";
  char *y = "gg";
  char z[3] = "rr";
  char a[2] = "jj";

  printf("size of x is:\t %lu\n", sizeof(x));
  printf("size of y is:\t %lu\n", sizeof(y));
  printf("size of z is:\t %lu\n", sizeof(z));
  printf("Contents of z is:\t %s\n", z);
  printf("size of a is:\t %lu\n", sizeof(a));
  printf("Contents of a is:\t %s\n", a);
  printf("size of t1.bDay is:\t %lu\n", sizeof(t1.bDay));
  printf("Contents of t1.Bday is:\t %s\n", t1.bDay);


  return 0;
}
