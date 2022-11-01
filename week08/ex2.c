#include <malloc.h>
#include <memory.h>
#include <unistd.h>

int main() {

    void *array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = malloc(1024 * 1024 * 10 * sizeof(char));
        memset(array[i], 0, 1024 * 1024 * 10 * sizeof(char));
        sleep(1);
    }
    /* Comments for Exercise 2:
     *
     * si and so are always 0.
     * We have enough space to store everything in Main memory, so we don't exceed it while allocating space
     * (10 times * 10 MB = 100 MB)
     * For the same reason swpd is 0 too */


    /* Comments for Exercise 3:
     *
     * First 5 lines correspoding to ex2:
     * PID 	USER   PR   NI   VIRT   RES     SHR S   %CPU  %MEM  TIME+  COMMAND
     * 3914 dangero+  20   0   33232  31748   1108 S   1,0   0,6   0:00.01 ex2
     * 3914 dangero+  20   0   43476  42044   1108 S   1,0   0,8   0:00.02 ex2
     * 3914 dangero+  20   0   63964  62636   1108 S   1,0   1,2   0:00.03 ex2
     * 3914 dangero+  20   0   84452  82964   1108 S   1,0   1,6   0:00.04 ex2
     * 3914 dangero+  20   0   94696  93260   1108 S   1,0   1,8   0:00.05 ex2
     *
     * During the execution only VIRT, RES and %MEM are changing.
     *
     * RES - Resident Memory Size inr KB - A subset of the virtual address space (VIRT) representing the  non-swapped
     *       physical memory a task is currently using. It is increasing, as more memory (10 MB) is allocated each second.
     * VIRT - Virtual Memory Size in KB - The total amount of virtual memory used by the task.
     *        It is increasing, as its part (RES) is increasing.
     * %MEM - RES divided by total physical memory. It is increasing, RES is increasing.
     */
    return 0;
}
