#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 비트 수를 세는 함수
int count_bits(int n) {
    if (!n) return 0;
    
    int count = 1;
    while(n > 1) {
        n = n >> 1;
        count++;
    }
    
    return count;
}

int solution(vector<int> num_list) {
    int answer = 0;
    
    // 최하위 비트를 무시하고 2씩 나누는 수
    // == 비트 수 - 1
    for (const int& n: num_list) {
        answer += count_bits(n) - 1;
    }
    
    return answer;
}