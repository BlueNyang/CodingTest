#include <string>
#include <vector>

using namespace std;

constexpr int k = 7;

// 숫자의 k 등장 횟수를 체크하는 함수
int digit_dp(int n) {
    int count = 0;
    
    while (n > 0) {
        if (n % 10 == k) count++;
        n /= 10;
    }
    
    return count;
}

int solution(vector<int> array) {
    int answer = 0;
    
    for (const int a: array) {
        answer += digit_dp(a);
    }
    
    return answer;
}