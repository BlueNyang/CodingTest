#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    const char delimiter = 'x';
    
    stringstream ss(myString);
    string token;
    vector<string> answer;
    
    while (getline(ss, token, delimiter)) {
        if (token != "") answer.emplace_back(token);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}