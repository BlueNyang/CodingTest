#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_pushed(string& A, string& B, int pos) {
    int len = A.length();
    
    for (int i = 0; i < len; i++) {
        if (A[i] != B[(i + pos) % len]) {
            return false;
        }
    }
    return true;
}

int solution(string A, string B) {
    int len = A.length();
    
    for (int i = 0; i < len; i++) {
        if (check_pushed(A, B, i)) {
            return i;
        }
    }
    
    return -1;
}