#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(string s) {
    istringstream iss(s);
    string subs;
    vector<string> str_vec;
    
    while (iss >> subs) {
        str_vec.push_back(subs);
    }
    
    int answer = 0;
    int previous = 0;
    
    for (const auto& str : str_vec){
        if (str == "Z") {
            answer -= previous;
        } else {
            istringstream converted(str);
            converted >> previous;
            answer += previous;
        }
    }
    
    return answer;
}