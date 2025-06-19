#include <string>

using namespace std;

string solution(string polynomial) {
    int x = 0, constant = 0;
    // + 기호를 패스하는 플래그
    bool __PASS_FLAG__ = false;
    
    int temp = 0;
    // 한글자씩 파싱
    for (const auto p: polynomial) {
        // 숫자인 경우
        if (p >= '0' && p <= '9') {
            // 숫자 하나씩 파싱
            temp *= 10;
            temp += p - '0';
            // 숫자가 나오면 우선 +는 유효
            __PASS_FLAG__ = false;
        }
        
        if (p == 'x') {
            // x가 나오면 일차 항에 적용
            if (temp == 0) x += 1;
            else x += temp;
            temp = 0;
            // 연산 했으니 다음 +는 패스
            __PASS_FLAG__ = true;
        }
        
        // + 기호가 유효하면
        if (p == '+' && !__PASS_FLAG__) {
            // 상수항에 적용
            if (temp != 0) constant += temp;
            temp = 0;
        }
    }
    
    // x나 +로 끝나지 않아 상수가 남는 경우
    if (temp != 0) constant += temp;
    
    string answer = "";
    
    // 일차항이 있으면
    if (x != 0) {
        // 1이면 생략
        if (x == 1) answer = "x";
        else answer = to_string(x) + "x";
    }
    
    // 상수항이 있으면
    if (constant != 0) {
        // 일차 항이 있으면 + 기호 추가
        if (answer != "") answer += " + ";
        answer += to_string(constant);
    }
    
    return answer;
}