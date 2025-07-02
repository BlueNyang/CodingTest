#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    auto it = find(num_list.begin(), num_list.end(), n);
    bool answer = it != num_list.end();
    return static_cast<int>(answer);
}