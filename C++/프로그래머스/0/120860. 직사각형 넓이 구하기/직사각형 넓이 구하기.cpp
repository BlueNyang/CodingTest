#include <vector>
#include <cstdlib>

using namespace std;

int solution(vector<vector<int>> dots) {
    int width = dots[0][0];
    
    for(const auto d: dots) {
        if (width != d[0]) {
            width -= d[0];
            break;
        }
    }
    
    int height = dots[0][1];
    
    for (const auto d: dots) {
        if (height != d[1]) {
            height -= d[1];
            break;
        }
    }
    
    return abs(width * height);
}