#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

#define VECTOR_SIZE 120

int main() {
    int u[VECTOR_SIZE];
    int v[VECTOR_SIZE];

    for (int i = 0; i < VECTOR_SIZE; i++) {
        int x = rand(), y = rand();
        u[i] = x % 100;
        v[i] = y % 100;
    }
    int n;
    fscanf(stdin, "%d", &n);
    pid_t pool[n];

    for (int i = 0; i < n; i++) {
        pool[i] = -1;
    }

    int block_size = VECTOR_SIZE / n;
    int dot = 0;

    FILE *pfile;
    pfile = fopen("temp.txt", "w");
    fputs("",pfile);

    pid_t main = getpid();
    for (int i = 0; i < n; i++) {
        pid_t curent_pid = getpid();
        if (main == curent_pid) {
            pid_t pid = fork();
            if (pid == 0) {
                pool[i] = getpid();
            } else {
                pool[i] = pid;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        pid_t current = getpid();
        if (pool[i] == current) {
            for (int j = i * block_size; j < (i + 1) * block_size; j++) {
                dot += u[j] * v[j];
            }
            fprintf(pfile, "%d\n", dot);
        }
    }

    if (main == getpid()) {
        fclose(pfile);
        pfile = fopen("temp.txt", "r");
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp = 0;
            wait(NULL);
            fscanf(pfile, "%d", &temp);
            dot+=temp;
        }
        fclose(pfile);
        pfile = fopen("temp.txt", "a");
        printf("%d\n", dot);
        fprintf(pfile, "\n%d\n", dot);
        fclose(pfile);
    }
    return 0;
}