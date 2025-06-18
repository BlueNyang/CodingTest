#include <string>

using namespace std;

string solution(int age) {
    string answer = "";
    
    if (age == 0) return "";
    else answer = solution(age / 10);
    
    answer += (char)(97 + age % 10);
    return answer;
}