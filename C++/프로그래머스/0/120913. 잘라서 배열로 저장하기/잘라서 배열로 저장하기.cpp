#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    // vector 메모리 재할당 횟수 감소를 위해 미리 길이 계산
    int vec_len = my_str.length();
    
    // 미리 공간 할당
    vector<string> answer;
    // 마지막 문자열이 n 미만일 경우를 대비해 + 1
    answer.reserve(vec_len / n + 1);
    
    for (int i = 0; i < vec_len; i += n) {
        answer.push_back(my_str.substr(i, n));
    }
    
    return answer;
}