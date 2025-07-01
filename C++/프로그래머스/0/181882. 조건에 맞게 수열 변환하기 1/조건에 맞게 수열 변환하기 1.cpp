#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    // 원본 배열 훼손 방지
    vector<int> answer(arr);
    
    for(int& i: answer) {
        if (i >= 50 && !(i % 2)) i /= 2;
        else if (i < 50 && i % 2) i *= 2;
    }
    
    return answer;
}