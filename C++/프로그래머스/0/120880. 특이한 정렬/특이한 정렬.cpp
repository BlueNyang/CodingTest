#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer(numlist);
    
    //sort 사용. lambda 함수
    sort(answer.begin(), answer.end(), [n](int a, int b) {
        // cmath의 절대값 함수 사용
        int na = abs(n - a), nb = abs(n - b);
        
        // n과 직선좌표계상 거리가 같으면
        if (na == nb) return a > b;
        // 아니면 거리 순 정렬
        return na < nb;
    });
    
    return answer;
}