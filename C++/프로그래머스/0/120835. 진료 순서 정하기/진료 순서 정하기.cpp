#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    map<int, int>temp;
    for (const auto e: emergency) temp[e] = 0;
    
    int count = temp.size();
    for (auto& t: temp) t.second = count--;
    
    vector<int> answer(emergency);
    for (auto& a: answer) a = temp[a];
    
    return answer;
}