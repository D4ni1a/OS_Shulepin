#include <stdio.h>

typedef struct {
    unsigned int id;
    unsigned int arrival_time;
    unsigned int burst_time;
    unsigned int start_time;
    unsigned int complete_time;
    unsigned int turnaround_time;
    unsigned int waiting_time;
} Process;

void swap(Process *xp, Process *yp);

void bubble_sort_arrival(int start, int finish, Process arr[]);
void bubble_sort_burst(int start, int finish, Process arr[], int n);

int main() {
    unsigned int n;

    double average_turnaround = 0;
    double average_waiting = 0;
    printf("Size:");
    fscanf(stdin, "%u", &n);

    Process jobs[n];

    printf("Input %d processes in format \"arrival_time burst_time\" (e.g. 0 1)\n",n);
    for (int i = 0; i < n; i++) {
        unsigned int m;
        fscanf(stdin, "%u", &m);
        jobs[i].arrival_time = m;

        fscanf(stdin, "%u", &m);
        jobs[i].burst_time = m;

        jobs[i].id = i;

        jobs[i].waiting_time = 0;
        jobs[i].turnaround_time = 0;
        jobs[i].start_time = jobs[i].arrival_time;
    }

    bubble_sort_arrival(0, n-1, jobs);


    int ind1, ind2;
    for (int i = 0; i < n; i++) {
        if (i==0){
            jobs[i].complete_time = jobs[i].start_time + jobs[i].burst_time;
            jobs[i].turnaround_time = jobs[i].complete_time - jobs[i].arrival_time;
            jobs[i].waiting_time = jobs[i].start_time - jobs[i].arrival_time;
        }
        else{
            ind1 = i; ind2 = i;
            for (int j = i; j<n;j++){
                if (jobs[j].arrival_time > jobs[i-1].complete_time) break;
                ind2 = j;
            }
            bubble_sort_burst(ind1, ind2, jobs, n);
            if (jobs[i-1].complete_time > jobs[i].arrival_time)
                jobs[i].start_time = jobs[i-1].complete_time;
            else
                jobs[i].start_time = jobs[i].arrival_time;
            jobs[i].complete_time = jobs[i].start_time + jobs[i].burst_time;
            jobs[i].turnaround_time = jobs[i].complete_time - jobs[i].arrival_time;
            jobs[i].waiting_time = jobs[i].start_time - jobs[i].arrival_time;
        }
        average_turnaround += jobs[i].turnaround_time;
        average_waiting += jobs[i].waiting_time;
    }


    average_waiting/=(double)n;
    average_turnaround/=(double)n;

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

void bubble_sort_burst(int start, int finish, Process arr[], int n) {
    for (int i = 0; i < finish - start; i++)
        for (int j = start; j < finish - i; j++)
            if (arr[j].burst_time > arr[j + 1].burst_time)
                swap(&arr[j], &arr[j + 1]);
}