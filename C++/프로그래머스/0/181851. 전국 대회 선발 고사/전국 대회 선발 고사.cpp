#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    map<int, int> att_rank;
    
    for (size_t i = 0; i < rank.size(); i++) {
        if (attendance[i])
            att_rank[rank[i]] = i;
    }
    
    int answer = 0;
    int init_digit = 10000;
    
    for (const auto& it: att_rank) {
        if (init_digit < 1) break;
        answer += init_digit * it.second;
        init_digit /= 100;
    }
    
    return answer;
}