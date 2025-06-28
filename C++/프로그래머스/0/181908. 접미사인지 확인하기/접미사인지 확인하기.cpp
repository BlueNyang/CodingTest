#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int idx = my_string.size() - is_suffix.size();
    if (idx < 0) return 0;
    return static_cast<int>(my_string.substr(idx) == is_suffix);
}