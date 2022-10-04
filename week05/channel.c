#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main() {
    int fd[2];
    size_t size;
    char restring[1024];
    if (pipe(fd) < 0) {
        printf("Error1!\n");
        exit(-1);
    }
    pid_t publisher;
    x:
    publisher = fork();
    if (publisher > 0) {
        pid_t subscriber = fork();
        if (subscriber == 0) {
            int n;
            waitpid(publisher, &n, 0);
            close(fd[1]);
            size = read(fd[0], restring, 1024);
            printf("%s\n", restring);
            close(fd[0]);
            exit(0);
        } else {
            int n;
            waitpid(publisher, &n, 0);
            waitpid(subscriber, &n, 0);
            sleep(1);
            goto x;
        }
    } else {
        close(fd[0]);
        char string[1024];
        fgets(string, 1024, stdin);
        size = write(fd[1], string, 1024);
        close(fd[1]);
        exit(0);
    }
}
