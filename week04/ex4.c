#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int compare_q(char str[]);

int main(int argc, char *argv[]) {
    char string[1024];
    printf("To quit press 'q'\n");
    while (1) {
        fgets(string, 1024, stdin);
        if ((compare_q(string)) == 0) break;
        pid_t pid = fork();
        if (pid == 0) {
            system(string);
            exit(0);
        }
    }
    wait(0);
    return 0;
}

int compare_q(char str[]) {
    if (str[0] == 'q' && str[1] == '\n') return 0;
    return 1;
}