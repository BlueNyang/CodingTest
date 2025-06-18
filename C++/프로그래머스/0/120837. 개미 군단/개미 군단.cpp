#include <string>
#include <vector>

constexpr int KNIGHT_ANT = 5;
constexpr int SOLDIER_ANT = 3;
constexpr int WORKER_ANT = 1;

using namespace std;

int solution(int hp) {
    int answer = hp / KNIGHT_ANT;
    int temp = hp % KNIGHT_ANT;
    
    answer += temp / SOLDIER_ANT;
    temp %= SOLDIER_ANT;
    
    answer += temp / WORKER_ANT;
    
    return answer;
}