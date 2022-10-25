#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>

void *reallocation(void *ptr, size_t new_size);

int main() {
    srand(time(NULL));

    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);

    int *a1 = malloc(sizeof(int) * n1);
    int i;
    for (i = 0; i < n1; i++) {
        *(a1 + i) = 100;
        printf("%d ", *(a1 + i));
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    a1 = reallocation(a1, sizeof(int) * n2);

    if (n2 > n1) {
        for (i = n1; i < n2; i++) {
            *(a1 + i) = 0;
        }
    }

    for (i = 0; i < n2; i++) {
        printf("%d ", *(a1 + i));
    }
    printf("\n");

    free(a1);

    return 0;
}


void *reallocation(void *old_ptr, size_t new_size) {
    size_t old_size = malloc_usable_size(old_ptr);
    size_t result_size = new_size < old_size ? new_size : old_size;

    if (new_size != 0) {
        void *new_ptr = malloc(new_size);
        if (old_ptr != NULL) {
            memcpy(new_ptr, old_ptr, result_size);
        }
        free(old_ptr);
        return new_ptr;
    } else {
        free(old_ptr);
        return NULL;
    }
}