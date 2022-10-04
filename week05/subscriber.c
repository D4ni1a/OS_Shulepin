#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char *myfifo = "/tmp/ex1";

    int temp = 1;
    if (argc > 1) sscanf(*(argv + 1), "%d", &temp);

    while (1) {
        fd = open(myfifo, O_RDONLY);
        char string[1024];
        if (fd==-1) break;
        if (read(fd, string, sizeof(string))==0)
        {
            printf("Terminal %d: %s\n", temp,string);
            sleep(1);
        }
        close(fd);
    }
    exit(0);
}