#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> indexed_players;
    vector<string> answer(players);
    
    for(size_t i = 0; i < answer.size(); i++) {
        indexed_players[answer[i]] = i;
    }
    
    for(const auto& c: callings) {
        int curr_idx = indexed_players[c];
        int prev_idx = curr_idx - 1;
        swap(answer[curr_idx], answer[curr_idx-1]);
        
        indexed_players[answer[curr_idx]] = curr_idx;
        indexed_players[answer[prev_idx]] = prev_idx;
    }
    return answer;
}