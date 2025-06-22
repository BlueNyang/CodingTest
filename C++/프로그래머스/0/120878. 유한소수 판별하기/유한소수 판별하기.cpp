#include <string>
#include <vector>

using namespace std;

// 최소공배수 함수 => 기약분수로 나누기 위함
int get_gcd(int a, int b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

// 소인수 리스트를 반환하는 함수
vector<int> get_prime_list(int n) {
    vector<int> primes;
    
    // 2로 나눠질 때
    if(n % 2 == 0) primes.push_back(2);
    while (n % 2 == 0) n /= 2;
    
    // 3이상의 소수로 나눠질 때
    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) primes.push_back(i);
        while(n % i == 0) n /= i;
    }
    
    // 처리 이후 n에 남은 값이 소수일 때
    if (n > 1) primes.push_back(n);
    
    return primes;
}

int solution(int a, int b) {
    // 최.공.배
    int gcd = get_gcd(a, b);
    
    // 분모의 소인수 리스트
    auto primes = get_prime_list(b / gcd);
    
    // 분모의 소인수 중 2나 5가 아닌게 있으면 2반환
    for (const auto p: primes) {
        if (p == 2 || p == 5) continue;
        return 2;
    }
    
    // 유한 소수면 1반환
    return 1;
}