#include <stdio.h>

typedef struct {
    unsigned int id;
    unsigned int arrival_time;
    unsigned int burst_time;
    unsigned int fake_burst_time;
    unsigned int complete_time;
    unsigned int turnaround_time;
    unsigned int waiting_time;
} Process;

void swap(Process *xp, Process *yp);

void bubble_sort_arrival(int start, int finish, Process arr[]);

int all_zero(Process process[], int n);

Process *poll(Process *array[], int *size, int *front, int capacity);

void offer(Process *array[], Process *value, int *size, int *front, int *rear, int capacity);

Process x = {.id = -1};

int main() {
    printf("Size:");
    unsigned int n;
    unsigned int quantum;

    double average_turnaround = 0;
    double average_waiting = 0;
    fscanf(stdin, "%u", &n);

    printf("Quantum:");
    fscanf(stdin, "%u", &quantum);

    Process jobs[n];

    printf("Input %d processes in format \"arrival_time burst_time\" (e.g. 0 1)\n",n);
    for (int i = 0; i < n; i++) {
        unsigned int m;
        fscanf(stdin, "%u", &m);
        jobs[i].arrival_time = m;

        fscanf(stdin, "%u", &m);
        jobs[i].burst_time = m;
        jobs[i].fake_burst_time = m;

        jobs[i].id = i;

        jobs[i].waiting_time = 0;
        jobs[i].turnaround_time = 0;
    }

    bubble_sort_arrival(0, n - 1, jobs);

    int current_time = 0;
    int flag = 0;

    int size = 0;
    int front = 0;
    int rear = 0;
    Process *queue[n];
    int last = 0;

    while (size == 0) {
        for (int i = 0; i < n; i++) {
            if (jobs[i].arrival_time == current_time) {
                offer(queue, &jobs[i], &size, &front, &rear, n);
                last = i;
            }
            if (jobs[i].arrival_time > current_time) break;
        }
        if (size == 0) current_time++;
    }

    while (all_zero(jobs, n) != 0) {
        Process *current = poll(queue, &size, &front, n);
        if (current->id!=-1) {
            if (current->fake_burst_time < quantum) {
                current_time += current->fake_burst_time;
                current->fake_burst_time = 0;
            } else {
                current_time += quantum;
                current->fake_burst_time -= quantum;
            }
        }

        for (int i = last+1; i < n; i++) {
            if (jobs[i].arrival_time <= current_time) {
                offer(queue, &jobs[i], &size, &front, &rear, n);
                last = i;
            }
            if (jobs[i].arrival_time > current_time) break;
        }
        if (current->id!=-1) {
            if (current->fake_burst_time != 0)
                offer(queue, current, &size, &front, &rear, n);
            else {
                current->complete_time = current_time;
                current->turnaround_time = current->complete_time - current->arrival_time;
                current->waiting_time = current->turnaround_time - current->burst_time;
                average_waiting += current->waiting_time;
                average_turnaround += current->turnaround_time;
            }
        }
        if (size == 0) current_time++;
    }

    average_waiting /= (double) n;
    average_turnaround /= (double) n;

    for (int i = 0; i <= n; i++) {
        if (i == 0)
            printf("%-8s\t%-15s\t%-15s\t%-12s\t%-15s\t  %-15s\n", "Process", "Arrival Time", "Burst Time",
                   "Complete Time", "Turnaround Time", "Waiting Time");
        else {
            printf("%-8u\t%-15u\t%-15u\t%-12u\t%-15u\t  %-15u\n",
                   jobs[i - 1].id, jobs[i - 1].arrival_time, jobs[i - 1].burst_time,
                   jobs[i - 1].complete_time, jobs[i - 1].turnaround_time, jobs[i - 1].waiting_time);
        }
    }
    printf("Average turnaround time: %lf\n", average_turnaround);
    printf("Average waiting time: %lf\n", average_waiting);

    return 0;
}

void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort_arrival(int start, int finish, Process arr[]) {
    for (int i = 0; i < finish - start; i++)
        for (int j = start; j < finish - i; j++)
            if (arr[j].arrival_time > arr[j + 1].arrival_time)
                swap(&arr[j], &arr[j + 1]);
}

int all_zero(Process process[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (process[i].fake_burst_time != 0) sum += 1;
    }
    return sum;
}

void offer(Process *array[], Process *value, int *size, int *front, int *rear, int capacity) {
    if (*size == 0) {
        *front = 0;
        *rear = 0;
        array[0] = value;
    } else {
        *rear = (*rear + 1) % capacity;
        array[*rear] = value;
    }
    if (*size != capacity) (*size)++;
    else *front = (*front + 1) % capacity;
}

Process *poll(Process *array[], int *size, int *front, int capacity) {
    if (*size!=0) {
        Process *value = array[*front];
        *front = (*front + 1) % capacity;
        (*size)--;
        return value;
    }
    return &x;
}