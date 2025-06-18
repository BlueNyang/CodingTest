#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    // y축 처리
    int answer = dot[1] > 0? 1 : 3;
    
    // x축 처리
    // x * y가 양수 이면 1, 3 분면
    // x * y가 음수 이면 2, 4 분면
    answer += dot[0] * dot[1] > 0 ? 0 : 1;
    return answer;
}