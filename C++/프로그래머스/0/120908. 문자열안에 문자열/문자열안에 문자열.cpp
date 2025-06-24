#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    size_t pos = str1.find(str2);
    return pos == string::npos ? 2 : 1;
}