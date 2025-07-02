#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    size_t n = arr.size();
    
    for (size_t y = 0; y < n; y++) {
        for (size_t x = y + 1; x < n; x++) {
            if (arr[y][x] != arr[x][y]) return 0;
        }
    }
    
    return 1;
}