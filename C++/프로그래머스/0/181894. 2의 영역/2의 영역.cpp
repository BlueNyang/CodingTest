#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    size_t s_pos = -1, e_pos = -1;
    
    for(size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) {
            if (s_pos == -1) {
                s_pos = i;
                e_pos = i + 1;
            }
            else {
                e_pos = i + 1;
            }
        }
    }
    
    if (s_pos == -1) return { -1 };
    return vector<int>(arr.begin() + s_pos, arr.begin() + e_pos);
}