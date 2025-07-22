#include <string>
#include <vector>

using namespace std;

bool check(const vector<int>& w, const vector<int>& b) {
    if ((w[0] >= b[0] && w[1] >= b[1]) ||
        (w[1] >= b[0] && w[0] >= b[1])) {
        return true;
    }
    return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    vector<int>c_bill(bill);
    
    int answer = 0;
    while(!check(wallet, c_bill)) {
        if (c_bill[0] > c_bill[1]) {
            c_bill[0] /= 2;
        } else {
            c_bill[1] /= 2;
        }
        answer++;
    }
    
    return answer;
}