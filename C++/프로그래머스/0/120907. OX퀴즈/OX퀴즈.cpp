#include <string>
#include <vector>

using namespace std;

string check_true(const string& formula) {
    size_t eq_pos = formula.find('=');
    
    string left = formula.substr(0, eq_pos);
    string right = formula.substr(eq_pos + 1);
    
    long long z = stoll(right);
    
    size_t parse_pos;
    long long x = stoll(left, &parse_pos);
    
    while (left[parse_pos] == ' ') parse_pos++;
    
    long long y = stoll(left.substr(parse_pos + 1));
    
    long long xy = left[parse_pos] == '+' ? x + y : x - y;
    
    if (xy == z) return "O";
    return "X";
    
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    answer.reserve(quiz.size());
    
    for(const auto& q: quiz) {
        answer.push_back(check_true(q));
    }
    
    
    return answer;
}