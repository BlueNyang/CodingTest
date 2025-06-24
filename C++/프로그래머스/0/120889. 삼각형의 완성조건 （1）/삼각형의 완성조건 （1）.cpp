#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int max = 0;
    int other = 0;
    
    for (const int s: sides) {
        if (max < s) {
            other += max;
            max = s;
        }
        else other += s;
    }
    
    if (other <= max) return 2;
    return 1;
}