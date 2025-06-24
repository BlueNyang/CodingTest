#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;;
    
    // 현재 인덱스 값
    int c_idx = 0;
    
    // 문자열 탐색
    while (c_idx < numbers.length()) {
        // 인지한 숫자 문자열 길이
        int num_len = 0;
        
        // 자릿수 증가
        answer *= 10;
        
        // 첫번째 글자를 이용해 빠르게 탐색
        switch (numbers[c_idx]) {
            case 'z':
                // z이면 zero가 맞는지 확인
                if (numbers.substr(c_idx, 4) == "zero")
                    num_len = 4;
                // 0이라서 덧셈은 없음
                break;
            case 'o':
                // one인지 확인
                if (numbers.substr(c_idx, 3) == "one") {
                    // 1 더하고 글자수 저장
                    answer += 1;
                    num_len = 3;
                }
                break;
            case 't':
                // t이면 two인지, three인지 확인
                if (numbers.substr(c_idx, 3) == "two") {
                    answer += 2;
                    num_len = 3;
                } else if (numbers.substr(c_idx, 5) == "three") {
                    answer += 3;
                    num_len = 5;
                }
                break;
            case 'f':
                if (numbers.substr(c_idx, 4) == "four") {
                    answer += 4;
                } else if (numbers.substr(c_idx, 4) == "five") {
                    answer += 5;
                }
                num_len = 4;
                break;
            case 's':
                if (numbers.substr(c_idx, 3) == "six") {
                    answer += 6;
                    num_len = 3;
                } else if (numbers.substr(c_idx, 5) == "seven") {
                    answer += 7;
                    num_len = 5;
                }
                break;
            case 'e':
                if (numbers.substr(c_idx, 5) == "eight") {
                    answer += 8;
                    num_len = 5;
                }
                break;
            case 'n':
                if (numbers.substr(c_idx, 4) == "nine") {
                    answer += 9;
                    num_len = 4;
                }
                break;
            default:
                break;
        }
        // 인식한 글자 수 만큼 인덱스 증가
        c_idx += num_len;
    }
    
    
    return answer;
}