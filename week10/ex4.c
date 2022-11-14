#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
    char **names;
} map;

int main() {
    DIR *dir;
    struct dirent *entry;

    map *dictionary = (map *) malloc(1 * sizeof(map));
    FILE *file;
    file = fopen("./ex4.txt", "a");

    dir = opendir("./tmp");
    if (!dir) {
        perror("diropen");
        exit(1);
    };

    int ind = 1;
    int flag;
    while ((entry = readdir(dir)) != NULL) {
        flag = 0;
        if (ind != 1) {
            for (int i = 0; i < ind - 1; i++) {
                if ((dictionary + i)->key == entry->d_ino) {
                    (dictionary + i)->value += 1;
                    (dictionary + i)->names[(dictionary + i)->value - 1] = malloc(256* sizeof(char));
                    strcpy((dictionary + i)->names[(dictionary + i)->value - 1],
                           entry->d_name);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                dictionary = (map *) realloc(dictionary, sizeof(map) * ind);
                (dictionary + (ind - 1))->key = entry->d_ino;
                (dictionary + (ind - 1))->value = 1;

                (dictionary + (ind - 1))->names = (char**)realloc((dictionary + (ind - 1))->names, (ind-1)*sizeof(char*));
                (dictionary + (ind - 1))->names[(dictionary + (ind - 1))->value - 1] = malloc(256* sizeof(char));
                strcpy((dictionary + (ind - 1))->names[(dictionary + (ind - 1))->value - 1],
                       entry->d_name);

                ind += 1;
            }
        } else {
            (dictionary + (ind - 1))->key = entry->d_ino;
            (dictionary + (ind - 1))->value = 1;

            (dictionary + (ind - 1))->names = (char**)malloc(1*sizeof(char*));
            (dictionary + (ind - 1))->names[(dictionary + (ind - 1))->value - 1] = malloc(256* sizeof(char));
            strcpy((dictionary + (ind - 1))->names[(dictionary + (ind - 1))->value - 1],
                   entry->d_name);

            ind += 1;
        }
    };

    closedir(dir);
    ind--;
//    fprintf(file,"File ---- Hard Links\n");
    printf("File ---- Hard Links\n");
    for (int j = 0; j < ind; j++) {
        if ((dictionary + j)->value >= 2) {
            for (int k = 0; k < (dictionary + j)->value; k++) {
//                fprintf(file,"%s ---- ", (dictionary + j)->names[k]);
                printf("%s ---- ", (dictionary + j)->names[k]);
                for (int l = 0; l < (dictionary + j)->value; l++) {
                    if (l != (dictionary + j)->value-1)
//                        fprintf(file,"%s, ", (dictionary+j)->names[l]);
                        printf("%s, ", (dictionary+j)->names[l]);
                    else
//                        fprintf(file,"%s\n", (dictionary+j)->names[l]);
                        printf("%s\n", (dictionary+j)->names[l]);
                }
            }
        }
    }

    for (int j = 0; j < ind; j++){
        free((dictionary + j)->names);
    }

    free(dictionary);
    free(dir);
    free(entry);

    return 0;
};
