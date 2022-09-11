#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count (char string[]);

void countAll (char string[]);

int main (){
    char string[256] = {'\0'};
    char temp;
    int size = 0;
    while ((temp = getchar())!='\n'){
        string[size++] = temp;
    }
    countAll(string);
    printf("\n");
    return 0;
}

void count (char string[]){
    if (string[strlen(string)-2]==' ' && string[strlen(string)-3]==','){
            char c = string[strlen(string) - 1];
        int count = 0;

        for (int i = 0; i < strlen(string) - 3; i++) {
            if (string[i] == toupper(c) || string[i] == tolower(c)) {
                count += 1;
            }
        }

        printf("%c:%d ", c, count);
    }
}

void countAll (char string[]){
    char str[256] = {'\0'};

    for (int i=0; i < strlen(string); i++){
        str[i] = string[i];
    }
    str[strlen(str)] = ',';
    str[strlen(str)] = ' ';
    int size = strlen(str);
    for (int i=0; i < strlen(string); i++){
        str[size] = tolower(string[i]);
        count(str);
    }
}
