#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = accumulate(included.cbegin(), included.cend(), 0,
                           [&] (int sum, const bool& element) {
                               if(element) sum += a;
                               a += d;
                               return sum;
                           });
    
    return answer;
}