#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    // 모두 소문자이므로 26개의 공간만 있으면 충분함.
    vector<int> count(26,0);
    int ascii_a = static_cast<int>('a');
    
    for(const auto b: before)
        count[static_cast<int>(b) - ascii_a]++;
    
    for(const auto a: after)
        count[static_cast<int>(a) - ascii_a]--;
    
    for(const auto c: count)
        if (c != 0) return 0;
    
    return 1;
}