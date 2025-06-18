#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer(numbers);
    
    if (direction == "right")
        rotate(answer.begin(), answer.end() - 1, answer.end());
    else
        rotate(answer.begin(), answer.begin() + 1, answer.end());
    
    return answer;
}