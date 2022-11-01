#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {

    void *array[10];
    for (int i = 0; i < 10; i++) {

        array[i] = malloc(1024 * 1024 * 10 * sizeof(char));
        memset(array[i], 0, 1024 * 1024 * 10 * sizeof(char));

        struct rusage *usage = malloc(1 * sizeof(struct rusage));

        int ret = getrusage(RUSAGE_SELF, usage);

        if (ret == 0) {
            printf("Maximum resident set size: %ld\n"
                   "Page reclaims (soft page faults): %ld\n", usage->ru_maxrss, usage->ru_minflt);
        }
        sleep(1);
    }


    return 0;
}
