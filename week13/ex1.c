#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int split(int **vector, char string[]) {
    *vector = malloc(sizeof(int) * 1);
    int number_of_elements = 1;
    char *token = strtok(string, " ");
    while (token != NULL) {
        int temp = atoi(token);
        *(*vector + number_of_elements - 1) = temp;
        number_of_elements++;
        *vector = realloc(*vector, sizeof(int) * number_of_elements);
        token = strtok(NULL, " ");
    }
    return number_of_elements - 1;
}

int main() {
    FILE *fp;
    char buff[255];

    int number_of_spaces = 0;
    int *E;
    int length_e;
    int *A;
    int length_a;
    int **C = malloc(sizeof(int *) * 1);
    int length_c_1 = 0;
    int length_c_2 = 0;
    int **R = malloc(sizeof(int *) * 1);
    int length_r_1 = 0;
    int length_r_2 = 0;
    fp = fopen("input.txt", "r");
    int i = 0;
    while (fgets(buff, 255, (FILE *) fp) != NULL) {
        if (strcmp(buff, "\n") != 0) {
            if (i == 0) {
                length_e = split(&E, buff);
                i++;
            } else if (i == 1) {
                length_a = split(&A, buff);
                i++;
            } else if (number_of_spaces == 2) {
                length_c_1 = split((C + length_c_2), buff);
                length_c_2 += 1;
                C = realloc(C, sizeof(int *) * (length_c_2 + 1));
                i++;

            } else if (number_of_spaces == 3) {
                length_r_1 = split((R + length_r_2), buff);
                length_r_2 += 1;
                R = realloc(R, sizeof(int *) * (length_r_2 + 1));
                i++;
            }
        } else {
            number_of_spaces++;
        }
    }

    if (length_a != length_c_1 || length_a != length_r_1 || length_r_2 != length_c_2
        || length_e != length_a) {
        printf("Input is invalid!\n");
        free(E);
        free(A);
        free(C);
        free(R);
        return 0;
    }


    int *F = malloc(sizeof(int) * 1);
    for (int l = 0; l < length_r_2; l++) {
        *(F + l) = 0;
        F = realloc(F, sizeof(int) * (l + 1));
    }

    int error = 0;
    int *Temp = malloc(sizeof(int) * 1);
    for (int l = 0; l < length_c_1; l++) {
        *(Temp + l) = 0;
        Temp = realloc(Temp, sizeof(int) * (l + 1));
    }
    for (int m = 0; m < length_c_2; m++) {
        for (int l = 0; l < length_c_1; l++) {
            *(Temp + l) += *(*(C + m) + l);
        }
    }
    for (int l = 0; l < length_c_1; l++) {
        *(Temp + l) += *(A + l);
    }

    for (int l = 0; l < length_c_1; l++) {
        if (*(Temp + l) != *(E + l)){
            printf("Input is invalid!\n");
            free(E);
            free(A);
            free(C);
            free(R);
            return 0;
        }
    }

    int temp = 0;
    while (1) {
        int k = 0;
        for (int l = 0; l < length_c_2; l++) {
            int flag = 0;
            if (F[l] == 0) {
                for (int j = 0; j < length_c_1; j++) {
                    if (R[l][j] <= A[j]) {
                        flag++;
                    }
                }
                if (flag == length_c_1) {
                    for (int j = 0; j < length_c_1; j++) {
                        A[j] += C[l][j];
                    }
                    F[l] = 1;
                    break;
                }
            }
            k++;
        }
        if (k == length_c_2) {
            for (int l = 0; l < length_c_2; l++) {
                if (F[l] == 1) {
                    temp++;
                }
            }
            if (temp == length_c_2) {
                printf("No deadlock!");
            } else {
                for (int l = 0; l < length_c_2; l++) {
                    if (F[l] == 0) {
                        printf("P%d\n", l);
                    }
                }
                printf("Deadlock detected!");
            }
            break;
        }
    }

    return 0;
}


