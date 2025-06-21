#include <string>

using namespace std;

int convert(int start, int end) {
    int count = 0;
    
    for (int i = start + 1; i <= end; i++) {
        // 배수 검사
        if (i % 3 == 0) {
            count++;
            continue;
        }
        
        // 3이 들어있는지 검사
        for (const auto& c: to_string(i)) {
            if(c == '3') {
                count++;
                break;
            }
        }
    }
    
    // 추가된 숫자들도 검사하여 return
    if (count == 0) return end;
    return convert(end, end + count);
}

int solution(int n) {
    return convert(0, n);
}