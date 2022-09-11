#include <stdio.h>

long long int tribonacci(int n);

int main (){
    printf("Tribonacci number 4: %lld\n",tribonacci(4));
    printf("Tribonacci number 36: %lld\n",tribonacci(36));
    return 0;
}

long long int tribonacci(int n){
    long long int Tn_3 = 0, Tn_2 = 1, Tn_1 = 1, Tn=0;
    if (n==0) return 0;
    else if (n==1 || n==2) return 1;
    else{
        for (int i = 3; i<n+1; i++){
            Tn = Tn_1 + Tn_2 + Tn_3;
            Tn_3 = Tn_2;
            Tn_2 = Tn_1;
            Tn_1 = Tn;
        }
        return Tn;
    }
}
