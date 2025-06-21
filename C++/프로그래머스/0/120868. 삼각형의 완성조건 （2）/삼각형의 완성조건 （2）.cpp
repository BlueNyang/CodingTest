#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> sides) {
    int diff = abs(sides[0] - sides[1]);
    return sides[0] + sides[1] - 1 - diff;
}