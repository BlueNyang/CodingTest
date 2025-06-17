#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    // 원본 vector 훼손 방지
    //auto answer(num_list);
    vector<int> answer(num_list);
    reverse(answer.begin(), answer.end());
    return answer;
}