#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2, 0);
        
    for(const auto n: num_list) answer[n % 2]++;
    
    return answer;
}