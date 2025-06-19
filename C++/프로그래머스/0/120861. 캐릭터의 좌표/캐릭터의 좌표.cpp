#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    // 원본 board 훼손 방지
    vector<int> answer = {0, 0};
    
    const vector<int> max_pos = {
        board[1] / 2, -board[1] / 2, //top, bottom
        board[0] / 2, -board[0] / 2, //right, left
    };
    
    for (const auto k: keyinput) {
        if (k == "up" && answer[1] + 1 <= max_pos[0]) {
            answer[1]++;
            continue;
        }
        
        if (k == "down" && answer[1] - 1 >= max_pos[1]) {
            answer[1]--;
            continue;
        }
        
        if (k == "right" && answer[0] + 1 <= max_pos[2]) {
            answer[0]++;
            continue;
        }
        
        if (k == "left" && answer[0] - 1 >= max_pos[3]) {
            answer[0]--;
            continue;
        }
    }
    
    return answer;
}