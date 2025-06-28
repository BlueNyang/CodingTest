#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    size_t len1 = intervals[0][1] - intervals[0][0] + 1;
    size_t len2 = intervals[1][1] - intervals[1][0] + 1;
    answer.reserve(len1 + len2);
    
    for(const auto& i: intervals) {
        answer.insert(answer.end(), arr.begin() + i[0], arr.begin() + i[1] + 1);
    }
    
    return answer;
}