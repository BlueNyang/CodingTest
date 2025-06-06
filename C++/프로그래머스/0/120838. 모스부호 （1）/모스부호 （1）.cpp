#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;


string solution(string letter) {
    map<string, string> morse = {
         {".-", "a" }, {"-...", "b" }, {"-.-.", "c" }, {"-..", "d" }, {".", "e" }, {"..-.", "f" }, {"--.", "g" }, {"....", "h" }, {"..", "i" }, {".---", "j" }, {"-.-", "k" }, {".-..", "l" },{"--", "m" }, {"-.", "n" }, {"---", "o" }, {".--.", "p" }, {"--.-", "q" }, {".-.", "r" }, {"...", "s" }, {"-", "t" }, {"..-", "u" }, {"...-", "v" }, {".--", "w" }, {"-..-", "x" }, {"-.--", "y" }, {"--..", "z" }
    };
    
    istringstream iss(letter);
    string subs = "";
    vector<string> words;
    
    while(iss >> subs) words.push_back(subs);
    
    stringstream ss;
    
    ss << "";
    
    for(const auto& word : words){
        ss << morse[word];
    }
    
    string answer = ss.str();
    
    return answer;
}