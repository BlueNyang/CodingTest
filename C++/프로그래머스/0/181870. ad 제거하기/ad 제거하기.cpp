#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    const string target_str = "ad";
    vector<string> answer;
    
    for(const auto& str: strArr) {
        if (str.find(target_str) == string::npos)
            answer.emplace_back(str);
    }
    
    return answer;
}