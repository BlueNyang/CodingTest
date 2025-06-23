#include <string>
#include <algorithm>

using namespace std;

// binary의 최대 길이
constexpr int MAX_LEN = 10;

string ulltos(unsigned long long n) {
    // n이 0이면 "0"
    if (n == 0) return "0";
    
    string bin;
    // 2진수 덧셈 결과의 길이는 최대길이 + 1 이하
    // 미리 공간을 할당하여 메모리 재할당 최소화
    bin.reserve(MAX_LEN + 1);
    
    // 2로 나누면서 binary로 변환
    while (n > 0) {
        // push_back을 하더라도 메모리 재할당이 없음
        bin.push_back((n % 2 == 0) ? '0' : '1');
        n /= 2;
    }
    
    // reverse
    reverse(bin.begin(), bin.end());
    
    return bin;
}

string solution(string bin1, string bin2) {
    // binary 문자열을 unsigned long long으로 변환(정수)
    unsigned long long bit1 = stoull(bin1, nullptr, 2);
    unsigned long long bit2 = stoull(bin2, nullptr, 2);
    
    // 정수 덧셈 결과를 binary로 변환
    return ulltos(bit1 + bit2);
}