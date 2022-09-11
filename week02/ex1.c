#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int x1 = INT_MAX;
    unsigned short int x2 = USHRT_MAX;
    signed long int x3 = LONG_MAX;
    float x4 = FLT_MAX;
    double x5 = DBL_MAX;
    printf("Integer size: %ld bytes and maximum value: %d\n\n",sizeof(x1),x1);
    printf("Unsigned short integer size: %ld bytes and maximum value: %d\n\n",sizeof(x2),x2);
    printf("Signed long integer size: %ld bytes and maximum value: %ld\n\n",sizeof(x3),x3);
    printf("Float size: %ld bytes and maximum value: %f\n\n",sizeof(x4),x4);
    printf("Double size: %ld bytes and maximum value: %f\n\n",sizeof(x5),x5);
    return 0;
}
