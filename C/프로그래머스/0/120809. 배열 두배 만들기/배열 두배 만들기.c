#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    int* answer = (int*)calloc(numbers_len, sizeof(int));
    for (int i = 0; i < numbers_len; i++) {
        answer[i] = numbers[i] << 1;
    }
    
    return answer;
}