#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    for(const auto& a: array)
        a > height ? answer++ : 0;
    
    return answer;
}