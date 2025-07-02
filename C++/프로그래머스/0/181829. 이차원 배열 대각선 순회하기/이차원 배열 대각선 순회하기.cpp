#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    for (size_t y = 0; y < board.size(); y++) {
        if (y > k) break;
        
        for (size_t x = 0; x < board[y].size(); x++) {
            if (x > k || y + x > k) break;
            answer += board[y][x];
        }
    }
    
    return answer;
}