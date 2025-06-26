#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer;
    answer.reserve(code.size());
    
    bool mode = false;
    
    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        
        if (code[i] == '1') mode = !mode;
        else if (mode && i % 2 == 1) answer += code[i];
        else if (!mode && i % 2 == 0) answer += code[i];
    }
    
    if (answer == "") return "EMPTY";
    return answer;
}