#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    unordered_map<int, int> group;
    
    for(const string& str: strArr) {
        group[str.length()]++;
    }
    
    auto it = max_element(group.begin(), group.end(),
                         [](const auto& a, const auto& b) {
                             return a.second <= b.second;
                         });
    
    return it->second;
}