#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    int count = 0;
    for(const int& c: myString) {
        if (c == 'x') {
            answer.emplace_back(count);
            count = 0;
        }
        else {
            count++;
        }
    }
    answer.emplace_back(count);
    
    return answer;
}