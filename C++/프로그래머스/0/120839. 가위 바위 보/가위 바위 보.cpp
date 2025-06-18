#include <string>
#include <vector>

using namespace std;

// switch 문 사용
char get_to_win(char a) {
    switch(a) {
        case '0':
            return '5';
        case '2':
            return '0';
        case '5':
            return '2';
        default:
            return '-1';
    }
    return '-1';
}

string solution(string rsp) {
    string answer = rsp;
    
    for (auto& a: answer) {
        a = get_to_win(a);
    }
    
    return answer;
}