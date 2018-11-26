// Program name: funcAddr.c
// Program shows how to get address of a function from other functions

#include<stdio.h>

void funct2();

void funct1()
{
    printf("--FUNCT1---\n");
    //printf("address of function main() is :%p\n", main);
    printf("address of function funct1() is : %p\n", funct1);
}

int main(void)
{
    printf("---MAIN---\n");
    printf("address of function main() is :%p\n", main);
    printf("address of function funct1() is : %p\n", funct1);
    printf("address of function funct2() is : %p\n", funct2);
    funct1();
    funct2();
    return 0;
}

void funct2()
{
    printf("--FUNCT2---\n");
    printf("address of function main() is :%p\n", main);
    printf("address of function funct2() is : %p\n", funct2);
}
