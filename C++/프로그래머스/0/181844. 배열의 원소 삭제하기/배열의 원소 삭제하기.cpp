#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for (const int& a: arr) {
        auto it = find(delete_list.begin(), delete_list.end(), a);
        if (it == delete_list.end()) {
            answer.emplace_back(a);
        }
    }
    
    return answer;
}