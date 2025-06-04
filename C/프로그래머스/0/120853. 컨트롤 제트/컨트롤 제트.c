#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    char* cpy_str = strdup(s);
    char* str_ptr = strtok(cpy_str, " ");
    int previous = 0, answer = 0;
    
    do{
        if (strcmp(str_ptr, "Z") == 0) answer -= previous;
        else{
            previous = atoi(str_ptr);
            answer += previous;
        }
    } while(str_ptr = strtok(NULL, " "));
    
    return answer;
}