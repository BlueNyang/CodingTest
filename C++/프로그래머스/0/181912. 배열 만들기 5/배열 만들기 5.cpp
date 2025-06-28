#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (const auto i: intStrs) {
        int x = stoi(i.substr(s, l));
        if (x > k) answer.push_back(x);
    }
    
    return answer;
}