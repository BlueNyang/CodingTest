#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int even = 0, odd = 0;
    
    for(size_t i = 0; i < num_list.size(); i++) {
        if (i % 2) even += num_list[i];
        else odd += num_list[i];
    }
    
    return max(even, odd);
}