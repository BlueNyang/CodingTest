#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getGCD(int a, int b) {
    return b == 0 ? a : getGCD(b, a % b);
}

int* solution(int numer1, int denom1, int numer2, int denom2) {
    int numer = numer1 * denom2 + numer2 * denom1;
    int denom = denom1 * denom2;
    
    int gcd = getGCD(numer, denom);
    
    int *answer = (int *)malloc(sizeof(int) * 2);
    // 메모리 할당 후 무조건 초기화(습관 형성)
    for (int i = 0; i < 2; i++) answer[i] = 0;
    
    answer[0] = numer / gcd;
    answer[1] = denom / gcd;
    
    return answer;
}