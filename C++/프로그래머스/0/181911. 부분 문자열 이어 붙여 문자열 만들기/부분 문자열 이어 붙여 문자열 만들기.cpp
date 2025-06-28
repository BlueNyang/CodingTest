#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    
    int vec_len = my_strings.size();
    for(int i = 0; i < vec_len; i++) {
        int len = parts[i][1] - parts[i][0] + 1;
        answer += my_strings[i].substr(parts[i][0], len);
    }
    
    return answer;
}