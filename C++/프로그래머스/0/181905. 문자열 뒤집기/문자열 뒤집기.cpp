#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    auto pBegin = my_string.begin();
    reverse(pBegin + s, pBegin + e + 1);
    return my_string;
}