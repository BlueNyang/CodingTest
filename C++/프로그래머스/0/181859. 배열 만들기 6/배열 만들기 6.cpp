#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(const int& a: arr) {
        if (!answer.size()) {
            answer.emplace_back(a);
        } else if (*(answer.rbegin()) == a) {
            answer.erase(answer.end() - 1);
        } else {
            answer.emplace_back(a);
        }
    }
    
    if (!answer.size()) return { -1 };
    return answer;
}