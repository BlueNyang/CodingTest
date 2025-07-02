#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int n = max(arr.size(), arr[0].size());
    
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    for (size_t y = 0; y < arr.size(); y++) {
        for (size_t x = 0; x < arr[y].size(); x++) {
            answer[y][x] = arr[y][x];
        }
    }
    
    return answer;
}