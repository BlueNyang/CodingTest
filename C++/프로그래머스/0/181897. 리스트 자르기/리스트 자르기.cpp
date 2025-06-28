#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    size_t len = num_list.size();
    int a = slicer[0], b = slicer[1] + 1, c = slicer[2];
    
    switch(n) {
        case 1:
            answer.reserve(b);
            copy(num_list.begin(), num_list.begin() + b,
                back_inserter(answer));
            break;
        case 2:
            answer.reserve(len - (a + 1));
            copy(num_list.begin() + a, num_list.end(),
                back_inserter(answer));
            break;
        case 3:
            answer.reserve(b - a);
            copy(num_list.begin() + a, num_list.begin() + b,
                back_inserter(answer));
            break;
        case 4:
            answer.reserve((b - a) / c);
            for (int i = a; i < b; i += c) {
                answer.emplace_back(num_list[i]);
            }
            break;
        default:
            break;
    }
    return answer;
}