#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int idx = 0;
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > array[idx]) idx = i;
    }
    
    return {array[idx], idx};
}