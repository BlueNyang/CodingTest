#include <string>
#include <vector>

using namespace std;

vector<int> get_tilt(vector<int> pos1, vector<int> pos2) {
    // 기울기 = dy/dx
    int dy = pos1[1] - pos2[1];
    int dx = pos1[0] - pos2[0];
    return {dy, dx};
}

int solution(vector<vector<int>> dots) {
    vector<vector<int>> tilt_list;
    vector<vector<int>> line_list = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 2}, {1, 3}, {2, 3}
    };
    
    for(const auto& l: line_list) {
        tilt_list.push_back(
            get_tilt(dots[l[0]], dots[l[1]])
        );
    }
    
    // 0-1|2-3, 0-2|1-3, 0-3|1-2
    // 0|5, 1|4, 2|3
    // dx1:dy1 = dx2:dy2 => dx1 * dy2 = dy1 * dx2
    for (int i = 0; i < 3; i++) {
        int ratio1 = tilt_list[i][0] * tilt_list[5 - i][1];
        int ratio2 = tilt_list[i][1] * tilt_list[5 - i][0];
        if (ratio1 == ratio2) 
            return 1;
    }
    
    return 0;
}