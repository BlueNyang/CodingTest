#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer(arr);
    
    size_t i = 0;
    if (!(answer.size() % 2)) ++i;
    
    for (i; i < arr.size(); i += 2) {
        answer[i] += n;
    }
    
    return answer;
}