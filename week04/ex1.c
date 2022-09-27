#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

int main() {
    clock_t main = clock();
    pid_t main_child_first_pid = fork();
    clock_t first = clock();
    pid_t current_pid = getpid();

    if (main_child_first_pid==0){
        pid_t parent_pid = getppid();
        printf("ID of the first child: %d, ID of his parent: %d and execution time: %lf miliseconds\n",current_pid,
               parent_pid, (double)1000*(clock()-first)/CLOCKS_PER_SEC);
    }
    else{
        pid_t main_child_second_pid = fork();
        clock_t second = clock();
        current_pid = getpid();
        if (main_child_second_pid==0){
            pid_t parent_pid = getppid();
            printf("ID of the second child: %d, ID of his parent: %d and execution time: %lf miliseconds\n",
                   current_pid, parent_pid, (double)1000*(clock()-second)/CLOCKS_PER_SEC);
        }
        else{
            wait(NULL);
            wait(NULL);
            pid_t parent_pid = getppid();
            printf("ID of the main process: %d, ID of his parent: %d and execution time: %lf miliseconds\n",
                   current_pid, parent_pid, (double)1000*(clock()-main)/CLOCKS_PER_SEC);
        }
    }
    return 0;
}
