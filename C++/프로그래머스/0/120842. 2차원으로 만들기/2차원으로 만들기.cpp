#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int count = num_list.size() / n;
    vector<vector<int>> answer;
    
    for(int i = 0; i < count; i++){
        vector<int> temp_array;
        for(int j = 0; j < n; j++) {
            temp_array.push_back(num_list[(i * n) + j]);
        }
        answer.push_back(temp_array);
    }
    
    return answer;
}