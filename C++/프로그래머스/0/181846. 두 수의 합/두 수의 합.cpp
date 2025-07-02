#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    
    // 올림수 플래그
    bool __FLAG_CARRY__ = false;
    
    // 1의 자리부터
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || __FLAG_CARRY__) {
        // 올림수 처리
        int sum = static_cast<int>(__FLAG_CARRY__);
        
        // 각 숫자 자리수 처리
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        // 올림수 체크
        __FLAG_CARRY__ = sum > 9;
        answer += to_string(sum %= 10);
    }
    
    // 거꾸고 계산한 뒤 reverse
    reverse(answer.begin(), answer.end());
    return answer;
}