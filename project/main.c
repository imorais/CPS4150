// Program name: main.c
// Purpose: This initializes a struct that contains some simple student information. The main function will call the //"called" function and pass the struct as an argument. The main function will also contain in-line assembler code to obtain and print the base pointer for the main function.
// Date: 11-25-2018
// Compile: gcc -o main main.c -m32

// By: Isabel Morais
// Class: CPS4150-01
// Assignment: Project

#include<stdio.h>

struct Students {
   int id;
   char fName[10];
   char lName[10];
   char bDay[2];
   char bMonth[2];
   char bYear[5];
};
// This must come after the Students struct is created or else it doesn't work.
int called(struct Students x, void *tmp);
void decToHexa(int n);

int main() {
    // Clarification line
    printf("---MAIN---\n");

    struct Students student = {12345, "Isabel", "Morais", "25", "06", "1997"};

    void *baseptr;
    // takes contents of %ebp and stores in baseptr
    asm("movl %%ebp, %0;": "=r"(baseptr));
    printf("The value of basepointer main:\t %p\n", baseptr);

    //Extra Credit
    void *stackptr;
    // takes contents of %esp and stores in stackptr
    asm("movl %%esp, %0;": "=r"(stackptr));
    printf("(Extra Credit)-->The value of stackpointer is:\t %p\n", stackptr);

    // print student info
    printf("ID:\t\t %d\n", student.id);
    printf("First Name:\t %s\n", student.fName);
    printf("Last Name:\t %s\n", student.lName);
    printf("Birth Day:\t %.2s\n", student.bDay);  // .2 formats the char so it only prints the first 2 characters
    printf("Birth Month:\t %.2s\n", student.bMonth);
    printf("Birth Year:\t %.4s\n", student.bYear);

    called(student, baseptr);

  return 0;
}

int called(struct Students x, void *tmp){

  // Clarification line
  printf("\n---CALLED---\n");

  void *baseptr;
  // takes contents of %ebp and stores in baseptr
  asm("movl %%ebp, %0;": "=r"(baseptr));
  printf("The value of basepointer print is:\t %p\n", baseptr);
  //This value is supposed to be the same value as the value for basepointer main in above
  printf("The value at basepointer address is:\t %p\n", tmp);

  printf("Address of id:\t\t %p\n", &x.id);
  printf("Address of fName:\t %p\n", &x.fName);
  printf("Address of lName:\t %p\n", &x.lName);
  printf("Address of bDay:\t %p\n", &x.bDay);
  printf("Address of bMonth:\t %p\n", &x.bMonth);
  printf("Address of bYear:\t %p\n", &x.bYear);

  char *ptrToDay = &x.bDay[0];
  int *ptrToDayInt = (int*)ptrToDay;
  printf("The address of my birth day and month is at address:\t %p\n", &x.bDay);
  printf("The integer value of my birth day and month is:\t\t %d\n", *ptrToDayInt);

  printf("\n");
  printf("----BYTE BY BYTE INFO----\n");  // This segment is for varification
  printf("*ptrToDay as a string is: %s\n", ptrToDay);
  printf("*ptrToDay (Address of bDay) is: %p\n", ptrToDay);
  printf("*ptrToDayInt (Integer value of bDay) is: %d\n", *ptrToDayInt);
  printf("The hex value of the int value above is: ");
  decToHexa(*ptrToDayInt);printf("\n");

  return 0;
}

// function to convert decimal to hexadecimal. Used for assurance that int vale of birthday and month is correct.
void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[15];
    // counter for hexadecimal number array
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;  // temporary variable to store remainder
        temp = n % 16;  // storing remainder in temp variable.
        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n/16;
    }
    // printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--)
        //cout << hexaDeciNum[j];
        printf("%c", hexaDeciNum[j]);
}
