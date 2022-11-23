#include "NumClass.h"

int isArmstrong(int num) {
    if((isArmstrongRec(num, digitCountRec(num))) == num) {
        return 1;
    }
    return 0;
}

int isArmstrongRec(int num, int len) {
    if(num == 0){
        return 0;
    }
    return power(num%10, len) + isArmstrongRec(num/10, len);
}

int isPalindrome(int num) {
    if(isPalindromeRec(num, 0) == num) {
        return 1;
    }
    return 0;
}

int isPalindromeRec(int num, int reverse) {
    if(num == 0) {
        return reverse;
    }
    return isPalindromeRec(num/10, (reverse*10 + num%10));
}

int digitCountRec(int num) {
    if(num == 0) {
        return 0;
    }
    return 1 + digitCountRec(num/10);
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