#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int temp = -1;
    
    for (size_t i = 0; i < speeds.size(); i++) {
        int remain = (99 - progresses[i]) / speeds[i] + 1;
        
        if (answer.empty() || remain > temp)
            answer.emplace_back(1);
        else
            ++(*answer.rbegin());
        
        if (remain > temp) temp = remain;
    }
    
    return answer;
}