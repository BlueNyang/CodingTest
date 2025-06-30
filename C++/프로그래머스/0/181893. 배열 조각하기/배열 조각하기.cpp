#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    size_t s_idx = 0, e_idx = arr.size();
    
    for (size_t i = 0; i < query.size(); i++) {
        if (i % 2) s_idx += query[i];
        else e_idx = s_idx + query[i] + 1;
    }
    
    return vector<int>(arr.begin() + s_idx, arr.begin() + e_idx);
}