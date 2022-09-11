#include <stdio.h>

int main(){
    char string[256] = {'\0'};
    char temp;
    int size = 0;
    printf("Type a string character-by-character:\n");
    while ((temp = getchar())!='.' && temp!='\n'){
        string[size++] = temp;
    }
    printf("\"");
    for (int i = size-1; i>=0; i--){
        printf("%c", string[i]);
    }
    printf("\"\n");
    return 0;
}

