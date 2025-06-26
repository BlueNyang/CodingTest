#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    bool is_right = false;
    if (ineq == "<") is_right = n < m;
    else if (ineq == ">") is_right = n > m;
    
    if (!is_right && eq == "=") is_right = n == m;
    
    if (is_right) return 1;
    return 0;
}