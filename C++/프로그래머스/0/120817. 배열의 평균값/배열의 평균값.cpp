#include <numeric>
#include <vector>

using namespace std;

double solution(vector<int> nums) {
    return accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
}