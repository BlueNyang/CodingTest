#include <string>
#include <vector>

using namespace std;

const string SUCCESS = "login";
const string FAILED = "fail";
const string WRONGPW = "wrong pw";

string solution(vector<string> id_pw, vector<vector<string>> db) {
    // db 순회
    for (const auto& e: db) {
        // id 찾음
        if (e[0] == id_pw[0]) {
            // pw 비교
            if (e[1] == id_pw[1]) return SUCCESS;
            return WRONGPW;
        }
    }
    return FAILED;
}