#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int n;
        sscanf(*(argv+1), "%d", &n);
        for (int i = 0; i<n; i++){
            fork();
            sleep(5);
        }
    }
    return 0;
}