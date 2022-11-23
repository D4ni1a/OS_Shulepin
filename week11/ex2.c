#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/");
    if (!dir) {
        perror("diropen");
        exit(1);
    }
    printf("Content of the root directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    free(entry);

    return 0;
}
