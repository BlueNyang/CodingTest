#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer;
    answer.reserve(arr.size());
    
    for (const string& str: arr) {
        answer += str;
    }
    
    return answer;
}