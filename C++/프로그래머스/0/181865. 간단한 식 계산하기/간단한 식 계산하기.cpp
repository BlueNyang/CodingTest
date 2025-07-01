#include <string>
#include <vector>
#include <sstream>

using namespace std;

int get_res(string a_origin, string b_origin, char op) {
    int a = stoi(a_origin), b = stoi(b_origin);
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return 0;
    }
}

int solution(string binomial) {
    stringstream ss(binomial);
    string token;
    
    string a, b, op;
    ss >> a >> op >> b;
    
    return get_res(a, b, op[0]);
}