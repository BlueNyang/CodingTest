#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    map<int, int> line_list;
    
    for(const auto& l: lines) {
        for (int i = l[0]; i < l[1]; i++) {
            line_list[i]++;
        }
    }
    
    int answer = 0;
    for (const auto& l: line_list)
        if (l.second > 1) answer++;
    
    return answer;
}