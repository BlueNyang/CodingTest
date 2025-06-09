#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#define COUNT_RESULT 5

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // 원본 배열을 망가뜨리지 않기 위해 배열을 복사
    int *n_list = (int*)malloc(sizeof(int) * num_list_len);
    memcpy(n_list, num_list, sizeof(int) * num_list_len);
    
    // 선택 정렬을 5번하면 된다.
    for (int i = 0; i < COUNT_RESULT; i++) {
        int min_idx = i;
        for (int j = i; j < num_list_len; j++) {
            if (n_list[min_idx] > n_list[j]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = n_list[i];
            n_list[i] = n_list[min_idx];
            n_list[min_idx] = temp;
        }
    }
    
    int* answer = (int*)malloc(sizeof(int) * COUNT_RESULT);
    memcpy(answer, n_list, sizeof(int) * COUNT_RESULT);
    free(n_list);
    
    return answer;
}