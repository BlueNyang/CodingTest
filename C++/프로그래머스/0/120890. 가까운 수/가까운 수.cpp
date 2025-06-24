#include <string>
#include <vector>

using namespace std;

int abs(int n) {
    if (n > 0) return n;
    else return 0 - n;
}

int solution(vector<int> array, int n) {
    int answer = 0;
    
    for (const int a: array) {
        if (answer == 0) answer = a;
        if (abs(n - a) < abs(n - answer)
            || (abs(n - a) == abs(n - answer) && a < answer))
            answer = a;
    }
    
    return answer;
}