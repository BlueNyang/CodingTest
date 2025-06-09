#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    // C와 달리 vector를 parameter로 받은 경우, 값에 의한 전달임
    // 원본에 영향을 미치지 않으므로, 그냥 사용
    // 정렬을 수행하지 않고, 작은 숫자를 순서대로 찾아 잘라넣음
    for (int i = 0; i < 5; i++) {
        int temp = 0;
        for(int j = 0; j < num_list.size(); j++) {
            if (num_list[temp] > num_list[j]) {
                temp = j;
            }
        }
        answer.push_back(num_list[temp]);
        num_list.erase(num_list.begin() + temp);
    }
    
    return answer;
}