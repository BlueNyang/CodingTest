#include <string>
#include <vector>

using namespace std;

vector<string> jokaBabb = {"aya", "ye", "woo", "ma"};

bool checkCanSpeak(string word) {
    if (word.length() == 0) return true;
    for (const auto& j : jokaBabb) {
        if (word.find(j) == 0) {
            return checkCanSpeak(word.substr(j.length()));
        }
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for(const auto& b : babbling) {
        if (checkCanSpeak(b))
            answer++;
    }
    return answer;
}