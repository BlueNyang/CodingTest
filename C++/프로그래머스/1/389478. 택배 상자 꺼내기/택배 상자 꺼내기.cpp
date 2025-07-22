#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int res = 0;
    
    while (num <= n) {
        num += (w - 1 - (w + num - 1) % w) * 2 + 1;
        res++;
    }
    
    return res;
}