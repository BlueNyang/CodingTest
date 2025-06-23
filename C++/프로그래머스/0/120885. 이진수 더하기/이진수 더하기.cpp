#include <string>
#include <vector>

using namespace std;

constexpr int BIT_LENGTH = 10;

string ulltos(unsigned long long n) {
    if (n == 0) return "0";
    
    string bin = "";
    
    // 2로 나누면서 binary로 변환
    while (n > 0) {
        bin = to_string(n % 2) + bin;
        n /= 2;
    }
    
    return bin;
}

string solution(string bin1, string bin2) {
    // binary 문자열을 unsigned long long으로 변환(정수)
    unsigned long long bit1 = stoull(bin1, nullptr, 2);
    unsigned long long bit2 = stoull(bin2, nullptr, 2);
    
    // 정수 덧셈 결과를 binary로 변환
    return ulltos(bit1 + bit2);
}