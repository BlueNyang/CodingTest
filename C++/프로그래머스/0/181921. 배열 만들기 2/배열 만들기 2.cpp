#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가능한 조합을 재귀적으로 구하는 함수
void get_variables(int cur, int l, int r, vector<int>& arr) {
    // 해당 요소가 l이상 r이하이면 push_back
    if (cur >= l && cur <= r) arr.push_back(cur);
    // r 이상이면 재귀 종료
    if (cur >= r) return;
    
    // 현재 수(5, 50, 55...)를 왼쪽으로 밀고, 0과 5를 대입해서 체크
    // cur이 5이면 50과 55를 체크
    cur *= 10;
    get_variables(cur, l, r, arr);
    get_variables(cur + 5, l, r, arr);
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    // 재귀함수 호출
    get_variables(5, l, r, answer);
    
    // 순서가 맞지 않게 나올 것이므로, sort하여 반환
    sort(answer.begin(), answer.end());
    
    // 없으면 -1이 있는 배열 반환
    if (answer.size() == 0) return { -1 };
    return answer;
}