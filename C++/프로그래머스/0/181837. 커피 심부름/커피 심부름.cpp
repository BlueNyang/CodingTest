#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for (const string& o: order) {
        // 오직 아메리카노와 카페 라테만 판매
        if (o.find("americano") != string::npos)
            answer += 4500;
        else if (o.find("anything") != string::npos)
            answer += 4500;
        else
            answer += 5000;
    }
    
    return answer;
}