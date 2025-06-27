#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(const string myString) {
    string answer = myString;    
    transform(answer.begin(), answer.end(), answer.begin(),
             [](unsigned char c) { return tolower(c); });
    return answer;
}