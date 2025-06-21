#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int temp = 0;
    
    for(const auto c: my_string) {
        // 글자의 ASCii 코드 값이 0 ~ 9 이면
        if (c >= '0' && c <= '9') {
            // 기존 temp에 10 곱하고
            temp *= 10;
            // ASCii 값을 이용해 수 확인
            temp += c - '0';
        }
        
        // 숫자가 아닌 경우
        else if (temp != 0) {
            // answer에 temp를 더하고 temp 초기화
            answer += temp;
            temp = 0;
        }
    }
    
    // 숫자로 끝나서 temp가 남은 경우
    // answer에 더함
    if (temp != 0) answer += temp;
    
    return answer;
}