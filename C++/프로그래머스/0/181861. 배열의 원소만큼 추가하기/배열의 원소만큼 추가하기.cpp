#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(const int& a: arr) {
        for(int i = 0; i < a; i++) {
            answer.emplace_back(a);
        }
    }
    
    return answer;
}