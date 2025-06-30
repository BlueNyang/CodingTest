#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer(num_list);
    
    rotate(answer.begin(), answer.begin() + n, answer.end());
    
    return answer;
}