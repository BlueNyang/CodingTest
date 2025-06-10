#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h> // memcopy

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    // 원본 훼손 방지
    int *arr = (int *)calloc(array_len, sizeof(int));
    memcpy(arr, array, array_len * sizeof(int));
    
    qsort(arr, array_len, sizeof(int), compare);
    
    return arr[array_len / 2];
}