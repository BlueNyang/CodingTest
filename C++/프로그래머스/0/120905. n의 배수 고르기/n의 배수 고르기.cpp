#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    answer.reserve(numlist.size());
    
    for(const auto& e: numlist) {
        if(e % n == 0) answer.push_back(e);
    }
    
    return answer;
}