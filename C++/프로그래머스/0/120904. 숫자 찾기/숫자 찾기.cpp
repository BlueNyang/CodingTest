#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 1;
    string num_str = to_string(num);
    
    for(const auto n: num_str) {
        if(n - '0' == k) break;
        answer++;
    }
    
    if (answer > num_str.length()) return -1;    
    return answer;
}