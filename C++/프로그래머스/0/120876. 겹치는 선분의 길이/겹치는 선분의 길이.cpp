#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    int min = 100, max = -100;
    map<int, int> line_list;
    
    for(const auto& l: lines) {
        for (int i = l[0]; i < l[1]; i++) {
            line_list[i]++;
            if (i < min) min = i;
            if (i > max) max = i;
        }
    }
    
    int answer = 0;
    for (const auto& l: line_list)
        if (l.second > 1) answer++;
    
    return answer;
}