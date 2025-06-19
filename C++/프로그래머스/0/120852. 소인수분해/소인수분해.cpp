#include <vector>
#include <set>

using namespace std;

// set는 중복이 없고 순서가 있기 때문에 쉽게 소인수를 가져옴
set<int> prime_factors(int n) {
    // 소인수
    set<int> primes;
    
    // 2배수 처리
    while (n % 2 == 0) {
        primes.insert(2);
        n /= 2;
    }
    
    // 기타 소수로 처리
    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            primes.insert(i);
            n /= i;
        }
    }
    
    // 처리 이후의 n이 소수인 경우 처리
    if (n > 1) primes.insert(n);
    
    return primes;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    // 소수 set
    auto primes = prime_factors(n);
    // vector로 변환
    answer.assign(primes.begin(), primes.end());
    
    return answer;
}