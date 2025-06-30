#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    size_t size = names.size();
    size % 5 ? size = size / 5 + 1 : size /= 5;
    
    vector<string> answer;
    answer.reserve(size);
    
    for (size_t i = 0; i < names.size(); i += 5)
        answer.push_back(names[i]);
    
    return answer;
}