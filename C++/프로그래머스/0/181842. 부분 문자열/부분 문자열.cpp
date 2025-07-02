#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    bool answer = str2.find(str1) != string::npos;
    return static_cast<int>(answer);
}