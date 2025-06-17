#include <string>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    // 원본 훼손 방지
    string answer = my_string;
    reverse(answer.begin(), answer.end());
    return answer;
}