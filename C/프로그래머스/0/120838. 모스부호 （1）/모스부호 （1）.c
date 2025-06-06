#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter) {
    char *morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    char *c_letter = (char *)malloc(1000 * sizeof(char));
    strcpy(c_letter, letter);
    
    char *ptr = strtok(c_letter, " ");
    char *temp = (char *)calloc(1000, sizeof(char));
    
    int index = 0;
    while (ptr != NULL) {
        int i = 0;
        while (strcmp(ptr, morse[i]) != 0) { i++; }
        temp[index] = (char)(97 + i);
        ptr = strtok(NULL, " ");
        index++;
    }
    
    char *answer = (char *)calloc(index, sizeof(char));
    memmove(answer, temp, sizeof(char) * index);
    free(temp);
    free(ptr);
    free(c_letter);
    return answer;
}