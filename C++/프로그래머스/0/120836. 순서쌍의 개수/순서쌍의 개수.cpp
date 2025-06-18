#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 소인수 분해
map<int,int> prime_factorize(int n) {
    std::map<int, int> factors;
    
    // 짝수 나누기
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    
    // 홀수 소수로 나누기
    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // n이 소수인 경우
    if (n > 1) factors[n]++;
    return factors;
}

int solution(int n) {
    // 약수의 갯수
    auto factors = prime_factorize(n);
    
    int answer = 1;
    // 지수가 0일 때도 포함하여 곱셈
    for(const auto f: factors) {
        answer *= (f.second + 1);
    }
    
    return answer;
}