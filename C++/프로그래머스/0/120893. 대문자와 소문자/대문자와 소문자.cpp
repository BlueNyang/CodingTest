#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    char gap = 'a' - 'A';
    
    for (auto& c: my_string) {
        if (c >= 'A' && c <= 'Z') c += gap;
        else if (c >= 'a' && c <= 'z') c -= gap;
    }
    return my_string;
}