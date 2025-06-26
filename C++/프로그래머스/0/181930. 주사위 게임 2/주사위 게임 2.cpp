#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = a + b + c;
    
    if (a == b || b == c || a == c)
        answer *= a * a + b * b + c * c;
    
    if (a == b && b == c)
        answer *= 3 * a * a * a;
    
    return answer;
}