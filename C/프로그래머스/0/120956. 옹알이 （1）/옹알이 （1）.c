#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *jokaBabb[] = {"aya", "ye", "woo", "ma"};
int num_jokaBabb = sizeof(jokaBabb) / sizeof(jokaBabb[0]);

bool checkCanSpeak(const char* pWord, size_t word_len) {
    if(word_len == 0) return true;
    
    for (char i = 0; i < num_jokaBabb; i++) {
        const char *j = jokaBabb[i];
        size_t j_len = strlen(j);
        
        if (word_len < j_len) continue;
        
        if(strncmp(pWord, j, j_len) == 0) {
            if (checkCanSpeak(pWord + j_len, word_len - j_len))
                return true;
        }
    }
    return false;
}

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    
    for (int k = 0; k < babbling_len; k++){
        size_t b_len = strlen(babbling[k]);
        if (checkCanSpeak(babbling[k], b_len)){
            answer++;
        }
    }
    
    return answer;
}