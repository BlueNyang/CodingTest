#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer;
    answer.reserve(numLog.size() - 1);
    
    int store = numLog[0];
    for(const int& n: numLog) {
        int move = n - store;
        if (move == 1) answer += "w";
        else if (move == -1) answer += "s";
        else if (move == 10) answer += "d";
        else if (move == -10) answer += "a";
        store = n;
    }
    
    return answer;
}