// Program name: main.c
// Purpose: This innitializes a struct that conains some simple student informaion. The mmain function will call the //"called" function and pass the struct as an argument. The main function will also contain in-line assembler code to obtain and print the base pointer for the main function.
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
   char bDay[3];
   char bMonth[3];
   char bYear[5];
};

// This must come after the Students struct is created or else it doesn't work.
int called(struct Students x);

int main() {

    struct Students student = {12345, "Isabel", "Morais", "25", "06", "1997"};

    void *baseptr;
    // takes contents of %ebp and stores in baseptr
    asm("movl %%ebp, %0;": "=r"(baseptr));

    printf("The value of basepointer main: \n");
    printf("%p\n", baseptr);
    // print student info
    printf("ID:\t\t %d\n", student.id);
    printf("First Name:\t %s\n", student.fName);
    printf("Last Name:\t %s\n", student.lName);
    printf("Birth Day:\t %s\n", student.bDay);
    printf("Birth Month:\t %s\n", student.bMonth);
    printf("Birth Year:\t %s\n", student.bYear);

    called(student);

  return 0;
}

int called(struct Students x){
  void *baseptr;
  // takes contents of %ebp and stores in baseptr
  asm("movl %%ebp, %0;": "=r"(baseptr));

  printf("The value of basepointer print is: \n");
  printf("%p\n", baseptr);

  void *stackptr;
  // takes contents of %ebp and stores in stackptr
  asm("movl %%esp, %0;": "=r"(stackptr));

  //This value is supposed to be the same value as the value for basepointer main in above
  printf("The value of basepointer address is: \n");
  printf("%p\n", baseptr);

  printf("-----This is a test!-----\n");
  printf("Address of id:\t\t %p\n", &x.id);
  printf("Address of fName:\t %p\n", &x.fName);
  printf("Address of lName:\t %p\n", &x.lName);
  printf("Address of bDay:\t %p\n", &x.bDay);
  printf("Address of bMonth:\t %p\n", &x.bMonth);
  printf("Address of bYear:\t %p\n", &x.bYear);
  printf("The address of my birth day and month is at address:\t %p\n", &x.bDay);

  return 0;
}
