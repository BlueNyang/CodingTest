#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(),
              [](unsigned char c) {return toupper(c); });
    return myString;
}