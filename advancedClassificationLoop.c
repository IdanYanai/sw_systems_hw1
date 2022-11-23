#include "NumClass.h"
#include <stdio.h>

int isArmstrong(int num) {
    int sum = 0;
    int copy = num;
    int len = 0;
    while(copy != 0) {
        len += 1;
        copy = (copy/10);
    }

    copy = num;
    for(int i=0;i<len;i++) {
        sum += power(copy%10, len);
        copy = (copy/10);
    }

    if(sum == num) {
        return 1;
    }
    return 0;
}

int isPalindrome(int num) {
    int copy = num;
    int reverse = 0;
    while(copy != 0) {
        reverse = (reverse*10) + (copy%10);
        copy /= 10;
    }
    if(reverse == num) {
        return 1;
    }
    return 0;
}

int power(int num, int p) {
    int toReturn = 1;
    if(num == 0) {
        return 0;
    }
    for(int i=0;i<p;i++) {
        toReturn = toReturn * num;
    }
    return toReturn;
}