#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    size_t real_pos = n_str.find_first_not_of('0');
    
    if (real_pos != string::npos) {
        n_str.erase(0, real_pos);
    }
    
    return n_str;
}