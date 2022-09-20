#include <stdio.h>

int foo (int age);

int main()
{
    const int x = 10;
    const int *q = &x;

    const int array[5];
    int * const p = array;

    for (int i = 0; i<5; i++){
	*(p+i)=x;
        fprintf(stdout, "%p\n",p+i);
    }
    fprintf(stdout, "\n");

    int temp;
    for (int i = 0; i<5; i++){
        fscanf(stdin, "%d", &temp);
        *(p+i)=temp;
    }

    int year;
    for (int i = 0; i<5; i++){
        year = foo(*(p+i));
        *(p+i)=year;
    }
    return 0;
}

int foo (int age){
    return 2022 - age;
}