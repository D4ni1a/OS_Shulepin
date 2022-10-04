#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;

    int temp = 1;
    if (argc > 1) sscanf(*(argv + 1), "%d", &temp);
    char *myfifo = "/tmp/ex1";


    mkfifo(myfifo, 0666);

    char arr2[1024];

    while (1) {
        fgets(arr2, 1024, stdin);
        fd = open(myfifo, O_WRONLY);
        for (int i = 0; i < temp+1; i++) {
            write(fd, arr2, strlen(arr2) + 1);
            sleep(1);
        }
        close(fd);
    }
}
