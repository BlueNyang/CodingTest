#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    answer.reserve(num_list.size() / n);
    
    for (size_t i = 0; i < num_list.size(); i += n) {
        answer.emplace_back(num_list[i]);
    }
    
    return answer;
}