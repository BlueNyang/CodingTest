#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer(arr);
    
    for (const auto& q: queries) {
        for (int i = q[0]; i <= q[1]; i++) {
            answer[i]++;
        }
    }
    
    return answer;
}