#include <stdio.h>

void convert (long long int x, int s, int t);

int check_number (long long int x, int s);

int check_base (int s);

long long int my_pow(int x, int y);

int main (){
    long long int number;
    int s, t;
    printf ("Input the number to be converted: ");
    scanf("%lld",&number);
    printf("Input the base of the source numeral system: ");
    scanf("%d",&s);
    printf("Input the base of the target numeral system: ");
    scanf("%d",&t);
    printf("Converting result: ");
    convert(number,s,t);
    return 0;
}

void convert (long long int x, int s, int t){
    int temp = check_number (x, s);
    temp += check_base(s);
    temp += check_base(t);

    if (temp==0){
        long long int result = x;
        char string[256] = {"\0"};
        int ind = 0;
        if (x==0){
            string[0] = 0;
            ind = 1;
        }
        if (s!=10){
            int index = 0;
            result = 0;
            while (x != 0) {
                result += (x%10*my_pow(s,index++));
                x = (x-x%10)/10;
            }
        }

        while (result!=0){
            string[ind++]=(char)(result%t);
            result = (result-result%t)/t;
        }
        for (int i=ind-1;i>=0;i--){
            printf("%d",string[i]);
        }
        printf("\n");
    }
    else {
        printf("cannot convert!\n");
    }
}

int check_number(long long int x, int s){
    int result = 0;
    if (x>=0) {
        while (x != 0) {
            if (x % 10 >= s) {
                result = 1;
            }
            x = (x - x % 10) / 10;
        }
    }
    else{
        result = 1;
    }
    return result;
}

int check_base(int x){
    int result = 0;
    if (x<2 || x>10){
        result = 1;
    }
    return result;
}

long long int my_pow(int x, int y){
    long long int temp = 1;
    for (int i=0; i<y; i++){
        temp*=x;
    }
    return temp;
}
