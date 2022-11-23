#include "NumClass.h"

int isPrime(int num) {
    if(num <= 0) {
        return 0;
    }
    for(int i=2;i<num;i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}

int isStrong(int num) {
    int sum = 0;
    int copy = num;
    while(copy!=0) {
        sum += (factorial(copy%10));
        copy = copy/10;
    }
    if(sum == num) {
        return 1;
    }
    return 0;
}

int factorial(int num) {
    int sum = 1;
    for(int i=2;i<=num;i++) {
        sum = sum*i;
    }
    return sum;
}