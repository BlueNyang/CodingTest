#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string,int>maps;
    
    for (size_t i = 0; i < name.size(); i++) {
        maps[name[i]] = yearning[i];
    }
    
    vector<int> answer;
    
    for (const auto& p: photo) {
        int score = 0;
        
        for (const auto& person: p) {
            score += maps[person];
        }
        answer.emplace_back(score);
    }
    
    return answer;
}