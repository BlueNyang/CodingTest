#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> seen(27, 0);
    
    // 매핑
    for (const auto& c: s) {
        seen[static_cast<int>(c - 'a')]++;
    }
    
    // 많은 재할당 방지
    string answer;
    answer.reserve(s.length());
    
    // 한 번만 등장했는지 확인
    for (int i = 0; i < seen.size(); i++) {
        if (seen[i] == 1) answer += i + 'a';
    }
    
    return answer;
}