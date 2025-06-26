#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    bool is_even = n % 2 == 0;
    int answer = 0;
    
    for (int i = 0; i <= n; i += 2) {
        if (is_even) answer += i * i;
        else answer += i + 1;
    }
    
    return answer;
}