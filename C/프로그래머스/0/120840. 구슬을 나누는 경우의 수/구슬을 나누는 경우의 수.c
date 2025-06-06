#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int balls, int share) {
    long answer = 1;
    for(int i = 0; i < share; i++) { answer *= (balls - i); answer /= (i + 1); }
    printf("%d\n", answer);
    return answer;
}