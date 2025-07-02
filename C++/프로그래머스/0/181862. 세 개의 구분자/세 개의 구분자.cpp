#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string myStr) {
    string delimiters = "abc";
    
    for (char& c: myStr) {
        if (delimiters.find(c) != string::npos) {
            c = ' ';
        }
    }
    
    stringstream ss(myStr);
    string token;
    vector<string> answer;
    
    while (ss >> token) {
        answer.emplace_back(token);
    }
    
    if (!answer.size()) answer.emplace_back("EMPTY");
    return answer;
}