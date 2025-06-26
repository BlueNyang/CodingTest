#include <string>
#include <vector>

using namespace std;

int get_min_arr_i(int s, int e, int k, vector<int>& arr) {
    int min = -1;
    for(int i = s; i <= e; i++) {
        if (arr[i] > k && (min == -1 || min > arr[i]))
            min = arr[i];
    }
    return min;
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    answer.reserve(queries.size());
    
    for (const auto& q: queries) {
        int n = get_min_arr_i(q[0], q[1], q[2], arr);
        answer.push_back(n);
    }
    
    return answer;
}