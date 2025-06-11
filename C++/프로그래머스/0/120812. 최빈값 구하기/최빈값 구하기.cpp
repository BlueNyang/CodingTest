#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    // frequency(빈도 수)를 unordered_map으로 저장
    unordered_map<int, int> freq;
    
    // freq 체크
    for(const auto& a: array) {
        freq[a]++;
    }
    
    // 선언 및 초기화
    int answer = array[0];
    int max_value = 0;
    
    // for(each)로 찾기
    for (const auto& f: freq) {
        // 동일한 max_value면 answer를 -1로
        if (f.second == max_value) answer = -1;
        // 상단 if문 실행 후 평가
        // 상단 if문이 현 if 이후 평가 시 무조건 -1
        if (f.second > max_value) {
            max_value = f.second;
            answer = f.first;
        }
    }
    
    return answer;
}