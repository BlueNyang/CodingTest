#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 간편하게 쓰기위해 typedef
typedef std::unordered_map<string,int> ClothesMap;

int solution(vector<vector<string>> clothes) {
    // 기본 값 1
    int answer = 1;
    // unordered_map 선언
    ClothesMap m;
    
    // 옷 종류별 카운트
    for(const auto& c: clothes) {
        if(m.count(c[1]) == 0) m.insert({c[1], 0});
        m[c[1]] += 1;
    }
    
    // 카운트한 수 곱연산
    for(auto elem : m){
        answer *= (elem.second + 1);
    }
    answer -= 1;
    
    return answer;
}