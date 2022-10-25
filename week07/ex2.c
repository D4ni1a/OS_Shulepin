#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Please, enter number N\n");
    scanf("%d", &N);

    int *array = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        *(array+i) = i;
    }

    for (int i = 0; i < N; i++){
        printf("%d ", *(array+i));
    }

    printf("\n");

    free(array);
    return 0;
}
