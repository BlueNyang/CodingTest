#include <string>
#include <vector>
#include <queue>

using namespace std;

// 트럭 정보
struct Truck {
    int weight;
    int exit_time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 트럭 대기 큐
    queue<int> truck_q;
    
    for (size_t i = 0; i < truck_weights.size(); i++) {
        // 무게를 저장
        truck_q.push(truck_weights[i]);
    }
    
    // 다리 큐
    queue<Truck> bridge_q;
    
    // 시간
    int time = 0;
    // 다리에 올라간 트럭들의 무게
    int current_weight = 0;
    
    while (!(truck_q.empty() && bridge_q.empty())) {
        ++time;
        
        // 브릿지에 트럭이 있는 경우
        if (!bridge_q.empty()) {
            auto bridge_f = bridge_q.front();
            // 위에 있던 트럭이 나가게 되는지 처리
            if (bridge_f.exit_time == time) {
                current_weight -= bridge_f.weight;
                bridge_q.pop();
            }
        }
        
        // 대기 트럭이 남은 경우
        if (!truck_q.empty()) {
            // 다음 트럭의 무게
            int next_truck_weight = truck_q.front();
            
            // 브릿지에 다음 트럭이 올라갈 수 있는 경우
            if (bridge_q.size() < bridge_length &&
                current_weight + next_truck_weight <= weight) {
                
                // 대기 트럭에서 제거
                truck_q.pop();
                
                // 브릿지에 편승
                bridge_q.push({
                    next_truck_weight,
                    time + bridge_length
                });
                
                // 무게 처리
                current_weight += next_truck_weight;
            }
        }
    }
    
    return time;
}