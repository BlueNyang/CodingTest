#include <string>
#include <vector>

using namespace std;

bool process_and_compare(vector<int>& arr) {
    vector<int> temp(arr);
    for (int& n: arr) {
        if(n >= 50 && !(n % 2))
            n = n >> 1;
        else if (n < 50 && n % 2)
            n = (n << 1) | 1;
    }
    return arr != temp;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    while (process_and_compare(arr)) {
        answer++;
    }
    
    return answer;
}