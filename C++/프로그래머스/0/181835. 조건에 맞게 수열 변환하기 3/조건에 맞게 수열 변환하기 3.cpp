#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(arr);
    bool is_odd = static_cast<bool>(k % 2);
    
    for(int& a: answer) {
        if (is_odd) a *= k;
        else a += k;
    }
    
    return answer;
}