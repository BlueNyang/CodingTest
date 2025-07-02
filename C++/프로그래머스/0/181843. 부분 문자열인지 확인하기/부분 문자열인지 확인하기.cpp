#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    bool answer = my_string.find(target) != string::npos;
    return static_cast<int>(answer);
}