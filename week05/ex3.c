#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int primes_count_in_interval(int start, int finish)
{
    int ret = 0;
    for (int i = start; i < finish; i++)
        if (is_prime(i) != 0)
            ret++;
    return ret;
}

typedef struct prime_counter_request
{
    int start, finish;
} prime_counter_request;

void *prime_counter(void *arg)
{
    prime_counter_request request = *(prime_counter_request *)arg;
    int *result = malloc(1*sizeof(int));
    *result = primes_count_in_interval(request.start, request.finish);
    return result;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]), n_threads = atoi(argv[2]);
    int segment_size = n / n_threads;

    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

    void **results = malloc(n_threads * sizeof(void *));

    for (int i = 0; i < n_threads; i++)
    {
        requests[i].start = i*segment_size;
        if (i==n_threads-1) requests[i].finish = n;
        else requests[i].finish = (i+1)*segment_size;
        int flag = pthread_create(&threads[i], NULL, prime_counter, &requests[i]);
        if (flag != 0){
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n_threads; i++)
    {
        pthread_join(threads[i], &results[i]);
    }

    int total_result = 0;
    for (int i = 0; i < n_threads; i++)
        total_result += *(int *)results[i];

    for (int i=0; i<n_threads; i++){
        free(*(results+i));
    }
    free(results);
    free(requests);
    free(threads);
    printf("%d\n", total_result);

    exit(EXIT_SUCCESS);
}