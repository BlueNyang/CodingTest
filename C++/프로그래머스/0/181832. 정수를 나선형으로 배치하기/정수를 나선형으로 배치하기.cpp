#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    
    int left = 0, top = 0, right = n - 1, bottom = n - 1;
    int count = 1;
    
    while (top <= bottom && left <= right) {
        // 상단 row
        for (int i = left; i <= right; i++) {
            answer[top][i] = count++;
        }
        top++;
        
        // 우측 column
        for (int i = top; i <= bottom; i++) {
            answer[i][right] = count++;
        }
        right--;
        
        // 하단 row
        for (int i = right; i >= left; i--) {
            answer[bottom][i] = count++;
        }
        bottom--;
        
        // 좌측 column
        for (int i = bottom; i >= top; i--) {
            answer[i][left] = count++;
        }
        left++;
        
    }
    
    return answer;
}

