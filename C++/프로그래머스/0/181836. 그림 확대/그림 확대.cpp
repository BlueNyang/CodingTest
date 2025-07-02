#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    answer.reserve(picture.size() * k);
    
    for (const auto& p: picture) {
        string temp = "";
        temp.reserve(p.length() * k);
        
        for (const auto& c: p) {
            temp.append(k, c);
        }
        
        answer.insert(answer.end(), k, temp);
    }
    
    return answer;
}