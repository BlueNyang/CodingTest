#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    int size = sqrt(n) * 2;
    vector<int> answer;
    answer.reserve(static_cast<size_t>(size));
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            answer.push_back(i);
            if (i * i != n) answer.push_back(n / i);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    
    return answer;
}