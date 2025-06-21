#include <string>
#include <vector>

using namespace std;

int count_str(string str, char target) {
    int count = 0;
    for (const auto& c: str) {
        if (c == target) count++;
    }
    return count;
}

int solution(vector<string> spell, vector<string> dic) {
    bool flag = false;
    for(const auto& str: dic) {
        for (const auto& s: spell) {
            if (count_str(str, s[0]) != 1) {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag) return 1;
    }
    
    return 2;
}