#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int get_res_in_2(map<int, int>& counts) {
    auto p_pt = counts.begin();
    auto q_pt = ++counts.begin();
    int p = p_pt->first, q = q_pt->first;
    
    if(p_pt->second == 2 && q_pt->second == 2) {
        return (p + q) * (q - p);
    } else {
        if (p_pt->second == 3) {
            return (10 * p + q) * (10 * p + q);
        } else {
            return (10 * q + p) * (10 * q + p);
        }
    }
}

int get_res_in_3(map<int, int>& counts) {
    int res = 1;
    for(const auto& c: counts) {
        if (c.second == 1)
            res *= c.first;
    }
    return res;
}

int solution(int a, int b, int c, int d) {
    vector<int> dice = {a, b, c, d};
    sort(dice.begin(), dice.end());
    
    map<int, int> counts;
    
    for (const int& d: dice) {
        counts[d]++;
    }
    
    int same = counts.size();
    
    if (same == 1) return 1111 * dice[0];
    if (same == 2) return get_res_in_2(counts);
    if (same == 3) return get_res_in_3(counts);
    if (same == 4) return dice[0];
}