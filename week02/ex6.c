#include <stdio.h>

int main (){
    printf("Input number of lines for each pattern: ");
    int number;
    scanf("%d",&number);
    for (int i=1; i < number+1; i++){
        for (int j=0; j< i; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    if (number%2==0){
        for (int i=1; i < number/2+1; i++){
            for (int j=0; j< i; j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i=number/2; i>0; i--){
            for (int j=0; j < i; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    else{
        for (int i=1; i < number/2+2; i++){
            for (int j=0; j< i; j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i=number/2; i>0; i--){
            for (int j=0; j < i; j++){
                printf("*");
            }
            printf("\n");
        }
    }

    printf("\n");

    for (int i=0; i < number; i++){
        for (int j=0; j< number; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
