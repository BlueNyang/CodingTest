#include <string>
#include <iostream>

using namespace std;

bool is_prime(int n) {
    int num = n;
    
    for (int i = 2; i < n; i++) {
        while (num % i == 0) num /= i;
    }
    
    return num > 1;
}

int solution(int n) {
    int answer = 0;
    
    for (int i = 4; i <= n; i++) {
        if(!is_prime(i)) {
            answer++;
        }
    }
    
    return answer;
}