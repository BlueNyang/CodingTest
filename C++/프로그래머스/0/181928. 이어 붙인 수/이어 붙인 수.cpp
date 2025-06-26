#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int com_even = 0, com_odd = 0;
    
    for(const int& n: num_list) {
        if (n % 2 == 0) {
            com_even *= 10;
            com_even += n;
        } else {
            com_odd *= 10;
            com_odd += n;
        }
    }
    
    return com_even + com_odd;
}