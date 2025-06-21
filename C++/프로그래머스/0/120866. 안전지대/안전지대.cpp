#include <string>
#include <vector>
#include <iostream>

using namespace std;

void check_bomb_area(vector<vector<int>>& b, int x, int y, int& count) {
    int n = b.size();
    
    // 폭탄(현재 칸) count에서 제거
    count--;
    
    // x, y 기준 반경 1칸(총 8칸) 순회
    for (int r = y - 1; r < y + 2; r++) {
        for (int c = x - 1; c < x + 2; c++) {
            // board의 범위 내이고 해당 칸이 0이면
            if (r > -1 && r < n && c > -1 && c < n && b[r][c] == 0) {
                // 체크하고 count 감소
                b[r][c] = -1;
                count--;
            }
        }
    }
    //순회 끝
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> c_board(board);
    
    // 전체 칸의 갯수
    int answer = n * n;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            // 이미 체크된(-1) 칸은 pass
            if (c_board[y][x] == -1) continue;
            // 폭탄이 있으면 check_bomb_area 실행
            if (c_board[y][x] == 1)
                check_bomb_area(c_board, x, y, answer);
        }
    }
    
    return answer;
}