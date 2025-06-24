#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 1;
    
    int temp = num; // 자릿수 계산용
    long long weight = 1; // 자릿수 가중치
    
    // 자릿수 가중치
    while(temp / 10 > 0) {
        weight *= 10;
        temp /= 10;
    }
    
    // 순회
    while(weight > 0) {
        // 숫자를 찾으면 index값 반환
        if (num / weight == k) return answer;
        // 아니면 계속 순회
        answer++;
        num %= weight;
        weight /= 10;
    }
    // 못찾고 순회가 끝나면 -1
    return -1;
}