#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string rny_string) {
    size_t m_count = count(rny_string.begin(), rny_string.end(), 'm');
    size_t size = rny_string.size() + m_count;
    
    string answer = "";
    answer.reserve(m_count);

    for(const char& c: rny_string) {
        if (c == 'm')
            answer += "rn";
        else
            answer += c;
    }
    
    return answer;
}