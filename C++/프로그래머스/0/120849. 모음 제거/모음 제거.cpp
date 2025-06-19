#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<char> gather = {'a', 'e', 'i', 'o', 'u'};

string solution(string my_string) {
    string answer = my_string;
    
    for(const auto g: gather)
        answer.erase(remove(answer.begin(), answer.end(), g), 
                     answer.end());
    
    return answer;
}