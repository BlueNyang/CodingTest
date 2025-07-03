#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int priority;
    
    Process(int idx, int prior)
        :pid(idx), priority(prior) {};
};

int solution(vector<int> priorities, int location) {
    // 우선순위 목록(높은 순서로 캐시);
    vector<int> prior_cache(priorities);
    sort(prior_cache.begin(), prior_cache.end(),
        [](const int& a, const int& b) {
            return a > b;
        });
    
    // 큐
    queue<Process> q;
    
    // 큐에 프로세스 추가
    for (size_t i = 0; i < priorities.size(); i++) {
        q.push(Process(i, priorities[i]));
    }
    
    int exec_count = 0;
    int cache_idx = 0;
    
    // queue가 비거나, target을 찾을 때까지
    while (!q.empty()) {
        // 제일 앞 대기 프로세스
        auto curr = q.front();
        q.pop(); // 꺼내기
        
        // 현재 프로세스가 실행 계획된 프로세스인 경우
        if (curr.priority == prior_cache[cache_idx]) {
            // 실행 처리
            ++exec_count;
            // target 프로세스를 찾으면 실행 순서 return
            if (curr.pid == location) return exec_count;
            // 캐시 인덱스 증가
            ++cache_idx;
        } else {
            // 실행할 Process가 아니면 제일 뒤로
            q.push(curr);
        }
    }
    
    
    return 0;
}