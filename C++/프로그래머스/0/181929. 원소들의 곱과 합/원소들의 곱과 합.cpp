#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int mul = 1;
    
    for (const int& n: num_list) {
        sum += n;
        mul *= n;
    }
    
    bool is_mul_less = mul < sum * sum;
    
    return static_cast<int>(is_mul_less);
}