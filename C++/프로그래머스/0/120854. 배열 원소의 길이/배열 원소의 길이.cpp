#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    for (const auto str: strlist) {
        answer.push_back(str.size());
    }
    
    return answer;
}