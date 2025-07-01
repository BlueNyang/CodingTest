#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    stringstream ss(my_string);
    string word;
    vector<string> answer;
    
    while (ss >> word) {
        answer.emplace_back(word);
    }
    
    return answer;
}