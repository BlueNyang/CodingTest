#include <string>
#include <vector>

using namespace std;

void count_mul(int s, int e, int k, vector<int>& arr) {
    int count = 0;
    for (int i = s; i <= e; i++) {
        if (i % k == 0) arr[i]++;
    }
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer(arr);
    
    for (const auto& q: queries) {
        count_mul(q[0], q[1], q[2], answer);
    }
    
    return answer;
}