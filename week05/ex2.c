#include <stdio.h>
#include <wait.h>
#include <pthread.h>
#include <string.h>

typedef struct{
    pthread_t id;
    int i;
    char message[256];
} Thread;

void *say_hello(void *arg);

int main(int argc, char* argv[]) {
    int n;
    if (argc>1) sscanf(*(argv + 1), "%d", &n);
    else n = 1;
    Thread thread[n];

    for (int i =0; i<n; i++) {
        char string1[] = "Hello from Thread ";
        char string2[256];
        sprintf(string2, "%d", i);
        strcat(string1,string2);
        thread[i].i = i;
        strncpy(thread[i].message, string1, 256);

        printf("\nThread %d is created\n", i);
        pthread_create(&thread[i].id, NULL, say_hello, &thread[i]);
        pthread_join(thread[i].id, NULL);
    }
    pthread_exit(NULL);
}

void *say_hello(void *arg){
    Thread thread = *(Thread*)arg;
    printf( "%s with id by \"pthread_self()\": %lu and id by \"gettid()\": %lu\n", thread.message, pthread_self(), gettid());
    pthread_exit(NULL);
    return NULL;
}