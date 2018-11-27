// Program name: main.c
// Purpose: This innitializes a struct that conains some simple student informaion. The mmain function will call the //"called" function and pass the struct as an argument. The main function will also contain in-line assembler code to obtain and print the base pointer for the main function.
// Date: 11-25-2018
// Compile: gcc -o main main.c -m32

// By: Isabel Morais
// Class: CPS4150-01
// Assignment: Project


#include<stdio.h>
#include<stdlib.h> //atoi()

struct Students {
   int id;
   char fName[10];
   char lName[10];
   char bDay[3];
   char bMonth[3];
   char bYear[5];
};

// This must come after the Students struct is created or else it doesn't work.
int called(struct Students x);
int toBin(int dno);

int main() {

    // testing purposes
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
    printf("(?)-->The value of stackpointer is:\t %p\n", stackptr);

    // print student info
    printf("ID:\t\t %d\n", student.id);
    printf("First Name:\t %s\n", student.fName);
    printf("Last Name:\t %s\n", student.lName);
    printf("Birth Day:\t %s\n", student.bDay);
    printf("Birth Month:\t %s\n", student.bMonth);
    printf("Birth Year:\t %s\n", student.bYear);
    printf("-->Address of main is %p\n", main);
    printf("-->Address of called is %p\n", called);

    called(student);

  return 0;
}

int called(struct Students x){

  // testing purposes
  printf("\n---CALLED---\n");

  void *baseptr;
  // takes contents of %ebp and stores in baseptr
  asm("movl %%ebp, %0;": "=r"(baseptr));

  printf("The value of basepointer print is:\t %p\n", baseptr);

  void *baseptr2;
  // takes contents of %ebp and stores in baseptr2
  asm("movl %%ebp, %0;": "=r"(baseptr2));

  //This value is supposed to be the same value as the value for basepointer main in above
  printf("The value of basepointer address is:\t %p\n", baseptr2);

  printf("What is in baseptr:\t\t\t %p\n", main);

  printf("-----Student Info-----\n");
  printf("Address of id:\t\t %p\n", &x.id);
  printf("Address of fName:\t %p\n", &x.fName);
  printf("Address of lName:\t %p\n", &x.lName);
  printf("Address of bDay:\t %p\n", &x.bDay);
  printf("Address of bMonth:\t %p\n", &x.bMonth);
  printf("Address of bYear:\t %p\n", &x.bYear);
  printf("The address of my birth day and month is at address:\t %p\n", &x.bDay);
  printf("The integer value of my birth day and month is:\t\t %d\n", 6666);

  printf("\n");
  printf("----BYTE BY BYTE INFO----\n");
  // Finds the decimal value of each byte in x.bDay
  printf("--bDay--\n");

  char numsAsChar[] = "";
  for (int i = 0; i < sizeof(x.bDay); ++i) {
    // Convert to unsigned char* because a char is 1 byte in size.
    // That is guaranteed by the standard.
    // Note that is it NOT required to be 8 bits in size.
    unsigned char byte = *((unsigned char *)&x.bDay + i);
    printf("Byte %d = %u\n", i, (unsigned)byte);
    numsAsChar[i] = byte;
    printf("->Char representaion of what is at byte %d: %c\n", i, numsAsChar[i]);
    int x;
    // Converts the character into an int and stores it in x
    x = atoi(&numsAsChar[i]);
    printf("->Decimal representaion of what is at byte %d: %d\n", i, x);
    printf("->Binary representaion of what is at byte %d: %04d\n", i, toBin(x));
  }
  // Finds the decimal value of each byte in x.bMonth
  printf("--bMonth--\n");
  for (int i = 0; i < sizeof(x.bMonth); ++i) {
    // Convert to unsigned char* because a char is 1 byte in size.
    // That is guaranteed by the standard.
    // Note that is it NOT required to be 8 bits in size.
    unsigned char byte = *((unsigned char *)&x.bMonth + i);
    printf("Byte %d = %u\n", i, (unsigned)byte);
  }

  return 0;
}

// Convert into to binary
int toBin(int dno)
{
    int bno=0,remainder,f=1;
    while(dno != 0)
    {
         remainder = dno % 2;
         bno = bno + remainder * f;
         f = f * 10;
         dno = dno / 2;
    }
    return bno;
}
