#include <string>
#include <vector>

using namespace std;

// algorithm의 count와 비슷함.
int count_str(string str, char target) {
    int count = 0;
    // 순회하면서 target의 갯수를 세서 반환
    for (const auto& c: str) {
        if (c == target) count++;
    }
    
    return count;
}

int solution(vector<string> spell, vector<string> dic) {
    // 찾았는지 확인하는 FLAG
    bool __FOUND_FLAG__ = false;
    
    // 순회
    for(const auto& str: dic) {
        // 스펠 순회
        for (const auto& s: spell) {
            // 하나만 들어있지 않으면 FLAG 회수 후 break;
            if (count_str(str, s[0]) != 1) {
                __FOUND_FLAG__ = false;
                break;
            }
            // break가 되지 않음 == 1만 있음
            // str에 spell 요소가 하나씩 만 있으면 FLAG는 유지됨
            __FOUND_FLAG__ = true;
        }
        // FLAG가 있으면 1반환
        if (__FOUND_FLAG__) return 1;
    }
    
    // 없으면 2반환
    return 2;
}