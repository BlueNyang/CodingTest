#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(string number) {
    int init = -number.size() * '0';
    auto total = reduce(number.begin(), number.end(), init);
    return total % 9;
}