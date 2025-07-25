#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for(size_t i = 0; i < arr.size(); i++) {
        if (flag[i]) {
            answer.insert(answer.end(), arr[i] * 2, arr[i]);
        } else {
            answer.erase(answer.end() - arr[i], answer.end());
        }
    }
    
    return answer;
}