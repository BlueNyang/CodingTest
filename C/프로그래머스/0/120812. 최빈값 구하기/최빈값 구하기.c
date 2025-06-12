#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int counts[1000];
    
    for (int i = 0; i < 1000; i++) {
        counts[i] = 0;
    }
    
    for (int i = 0; i < array_len; i++) {
        counts[array[i]]++;
    }
    
    int answer = -1;
    int max_value = 0;
    int count_value = 0;
    
    for (int i = 0; i < 1000; i++ ) {
        if (counts[i] == 0) continue;
        if (counts[i] == max_value) answer = -1;
        if (counts[i] > max_value) {
            answer = i;
            max_value = counts[i];
        }
    }
    
    return answer;
}