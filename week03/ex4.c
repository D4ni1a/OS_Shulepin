#include <stdio.h>

void* add_int(const void* a, const void* b);

void* mean_int(const void* a, const void* b);

void* multiplication_int(const void* a, const void* b);

void* add_double(const void* a, const void* b);

void* mean_double(const void* a, const void* b);

void* multiplication_double(const void* a, const void* b);

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

int main()
{
    double array_double[] = {1.5,2.5,3.5,4.5,5.0};
    double sum_double = 0;
    double *ptr_sum_double = &sum_double;
    aggregate(array_double, 8, 5, ptr_sum_double, add_double);
    printf("Sum of doubles: %f\n", sum_double);

    double mult_double = 1;
    double *ptr_mult_double = &mult_double;
    aggregate(array_double, 8, 5, ptr_mult_double, multiplication_double);
    printf("Multiplication of doubles: %f\n", mult_double);

    double mean_d = 0;
    double *ptr_mean_d = &mean_d;
    aggregate(array_double, 8, 5, ptr_mean_d, mean_double);
    printf("Mean of doubles: %f\n", mean_d);

    printf("\n");

    int array_int[] = {1,2,3,4,5};
    int sum_int = 0;
    int *ptr_sum_int = &sum_int;
    aggregate(array_int, 4, 5, ptr_sum_int, add_int);
    printf("Sum of integers: %d\n", sum_int);

    int mult_int = 1;
    int *ptr_mult_int = &mult_int;
    aggregate(array_int, 4, 5, ptr_mult_int, multiplication_int);
    printf("Multiplication of integers: %d\n", mult_int);

    int mean_i = 0;
    int *ptr_mean_i = &mean_i;
    aggregate(array_int, 4, 5, ptr_mean_i, mean_int);
    printf("Mean of integers: %d\n", mean_i);

    return 0;
}

void* mean_int(const void* a, const void* b){
    int *x = a;
    int *y = b;
    *x += *y;
    return x;
}

void* mean_double(const void* a, const void* b){
    double *x = a;
    double *y = b;
    *x += *y;
    return x;
}

void* add_int(const void* a, const void* b){
    int *x = a;
    int *y = b;
    *x += *y;
    return x;
}

void* add_double(const void* a, const void* b){
    double *x = a;
    double *y = b;
    *x += *y;
    return x;
}

void* multiplication_int(const void* a, const void* b){
    int *x = a;
    int *y = b;
    *x *= *y;
    return x;
}

void* multiplication_double(const void* a, const void* b){
    double *x = a;
    double *y = b;
    *x *= *y;
    return x;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    if (size==sizeof(int)){
        if (opr==mean_int){
            int *result = initial_value;
            for (int i = 0; i<n; i++)
                mean_int(result, base+i*sizeof(int));
            *result = *result / n;
            return result;
        }
        else if (opr==multiplication_int){
            for (int i = 0; i<n; i++)
                multiplication_int(initial_value, base+i*sizeof(int));
            return initial_value;
        }
        else if (opr==add_int){
            int result = 0;
            for (int i = 0; i<n; i++)
                add_int(initial_value, base+i*sizeof(int));
            return initial_value;
        }
    }
    else if (size==sizeof(double)){
        if (opr==mean_double){
            double * result = initial_value;
            for (int i = 0; i<n; i++)
                mean_double(result, base+i*sizeof(double));
            *result = *result / n;
            return result;
        }
        else if (opr==multiplication_double){
            for (int i = 0; i<n; i++)
                multiplication_double(initial_value, base+i*sizeof(double));
            return initial_value;
        }
        else if (opr==add_double){
            for (int i = 0; i<n; i++)
                add_double(initial_value, base+i*sizeof(double));
            return initial_value;
        }
    }
}