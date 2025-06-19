#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    int end_idx = numbers.size() - 1;
    
    int min_s = numbers[0] * numbers[1];
    int max_s = numbers[end_idx] * numbers[end_idx - 1];
    
    return max(max_s, min_s);
}