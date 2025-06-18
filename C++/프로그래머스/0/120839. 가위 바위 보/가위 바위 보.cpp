#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = rsp;
    
    for (auto& a: answer) {
        switch(a) {
            case '0':
                a = '5';
                break;
            case '2':
                a = '0';
                break;
            default:
                a = '2';
                break;
        }
    }
    
    return answer;
}