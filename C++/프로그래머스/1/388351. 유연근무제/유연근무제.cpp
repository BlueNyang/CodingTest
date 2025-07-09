#include <string>
#include <vector>

using namespace std;

bool check_success(int des_time, const vector<int>& timelog, int startday) {
    int s_idx = 8 - startday;
    
    if (des_time % 100 >= 50) {
        des_time += 50;
    } else {
        des_time += 10;
    }
    
    for (int i = s_idx; i < s_idx + 5; i++) {
        if (des_time < timelog[i % 7]) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (size_t i = 0; i < schedules.size(); i++) {
        int desired_time = schedules[i];
        if (check_success(desired_time, timelogs[i], startday)) {
            answer++;
        }
    }
    
    
    return answer;
}