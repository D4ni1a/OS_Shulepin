#include <stdio.h>
#include <limits.h>
#define REFERRED 32

struct page{
    int number;
    short R[REFERRED];
};

int is_element(int element, struct page frame[], int number);

int find_min(struct page frame[], int n);

int sum(struct page one);

int my_pow(int x, int y);

int main() {
    int n;
    fprintf(stdout,"Please, enter the number of page frames\n");
    fscanf(stdin, "%d", &n);

    struct page frame[n];

    for (int i = 0; i < n; i++){
        frame[i].number = -1;
        for (int j = 0; j < REFERRED; j++){
            frame[i].R[j] = 0;
        }
    }

    FILE *open;
    open = fopen("Lab 09 input.txt","r");

    int element;
    int hits = 0;
    int misses = 0;
    int status;
    int numbers = 0;

    while (fscanf(open,"%d",&element)==1){
        status = is_element(element, frame, n);
        numbers++;
        if (status != -1){
            hits++;

            for (int i = 0; i < n; i++){
                for (int j = REFERRED - 1; j > 0; j--){
                    frame[i].R[j] = frame[i].R[j-1];
                }
                frame[i].R[0] = 0;
            }

            frame[status].R[0] = 1;

        }
        else{
            misses++;

            int min_index = find_min(frame, n);

            for (int i = 0; i < n; i++){
                for (int j = REFERRED - 1; j > 0; j--){
                    frame[i].R[j] = frame[i].R[j-1];
                }
                frame[i].R[0] = 0;
            }

            frame[min_index].number = element;
            frame[min_index].R[0] = 1;
            for (int i = 1; i < REFERRED; i++){
                frame[min_index].R[i] = 0;
            }
        }
    }

    printf("Hit: %d, %f\nMiss: %d, %f\nHit/Miss ratio: %f\n", hits, (float)hits/(float)numbers, misses,
           (float)misses/(float)numbers, (float)hits/(float)misses);
    fclose(open);
    return 0;
}

int is_element(int element, struct page frame[], int number){
    if (frame!=NULL){
        for (int i = 0; i < number; i++){
            if (frame[i].number == element){
                return i;
            }
        }
    }
    return -1;
}

int find_min(struct page frame[], int n){
    int min = INT_MAX;
    int index = 0;
    for (int i = 0; i < n; i++){
        int s = sum(frame[i]);
        if (frame[i].number < 0){
            return i;
        }
        else if (s < min){
            min = s;
            index = i;
        }
    }
    return index;
}

int sum(struct page one){
    int sum = 0;
    int temp;
    for (int i = 0; i < REFERRED; i++){
        temp = my_pow(2, i);
        sum += (one.R[REFERRED-i-1] * temp);
    }
    return sum;
}

int my_pow(int x, int y){
    int temp = 1;
    for (int i = 0; i<y; i++){
        temp*=x;
    }
    return temp;
}
