#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    // 원본 훼손 방지를 위해 복사
    string answer = my_string;
    
    // letter의 길이는 1이므로 (char)letter[0]로 변환
    // 제거할 문자들을 끝으로 옮기고, 논리적인 새 끝 반환 O(n)
    auto newEnd = remove(answer.begin(), answer.end(), letter[0]);
    
    // 새 논리적 끝부터 실제 끝(제거할 문자들) 제거
    answer.erase(newEnd, answer.end());
    
    return answer;
}