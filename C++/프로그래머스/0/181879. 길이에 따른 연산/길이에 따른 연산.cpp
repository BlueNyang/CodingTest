#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    bool is_over_10 = num_list.size() > 10;
    if (!is_over_10) ++answer;
    
    for (const int& n: num_list) {
        if (is_over_10) answer += n;
        else answer *= n;
    }
    
    return answer;
}