#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string str, int num1, int num2) {
    swap(str[num1], str[num2]);
    return str;
}