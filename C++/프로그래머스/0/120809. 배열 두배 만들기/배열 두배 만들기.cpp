#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    transform(numbers.begin(), numbers.end(), answer.begin(),
              [](int x){ return x << 1; });
    
    return answer;
}