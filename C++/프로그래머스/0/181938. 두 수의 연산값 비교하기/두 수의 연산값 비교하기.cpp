#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b) {
    int weight = 1;
    while (weight < b) weight *= 10;
    
    int ab = a * weight + b;
    //int ab = stoi(to_string(a) + to_string(b));
    
    return max(ab, 2 * a * b);
}