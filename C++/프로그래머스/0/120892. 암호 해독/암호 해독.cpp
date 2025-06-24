#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer;
    answer.reserve(cipher.length() / code + 1);
    
    for (int i = code - 1; i < cipher.length(); i += code)
        answer += cipher[i];
    
    return answer;
}