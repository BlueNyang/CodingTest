#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    answer.reserve(k);
    
    for(const int& a: arr) {
        auto it = find(answer.begin(), answer.end(), a);
        if (answer.empty() || it == answer.end())
            answer.emplace_back(a);
        
        if (answer.size() == k) break;
    }
    
    for(size_t i = answer.size(); i < k; i++) {
        answer.emplace_back(-1);
    }
    
    return answer;
}