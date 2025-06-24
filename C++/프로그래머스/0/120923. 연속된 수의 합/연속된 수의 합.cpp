#include <string>
#include <vector>

using namespace std;

// total = x + (x + 1) ... (x + n-1)
// total = nx + sum(0 ~ n-1);
// total = nx + n(n-1)/2;
// nx = total - n(n-1)/2;
// x = (total - n(n-1)/2) / n
vector<int> solution(int num, int total) {
    int x = (total - num * (num - 1) / 2) / num;
    
    vector<int> answer(num, 0);
    for (int i = 0; i < num; i++)
        answer[i] = x + i;
    
    return answer;
}