#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int first = 0, second = 0;
    
    for(const auto n: numbers) {
        // 큰 수를 찾으면
        if (n > first) {
            // 이전 max는 second에
            second = first;
            // 새 max는 first에
            first = n;
            continue;
        }
        
        // second도 max 값 탐색
        if (n > second) {
            second = n;
        }
    }
    
    return first * second;
}