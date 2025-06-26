#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer(arr);
    
    for (const auto& q: queries) {
        swap(answer[q[0]], answer[q[1]]);
    }
    
    return answer;
}