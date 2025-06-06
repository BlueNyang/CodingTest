using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string letter) {
        var mors = new Dictionary<string, string>(){
    {".-", "a" }, {"-...", "b" }, {"-.-.", "c" }, {"-..", "d" }, {".", "e" }, {"..-.", "f" }, {"--.", "g" }, {"....", "h" }, {"..", "i" }, {".---", "j" }, {"-.-", "k" }, {".-..", "l" },{"--", "m" }, {"-.", "n" }, {"---", "o" }, {".--.", "p" }, {"--.-", "q" }, {".-.", "r" }, {"...", "s" }, {"-", "t" }, {"..-", "u" }, {"...-", "v" }, {".--", "w" }, {"-..-", "x" }, {"-.--", "y" }, {"--..", "z" } };
        
        string answer = "";
        
        var words = letter.Split(' ');
        
        foreach (var w in words) {
            answer += mors[w];
        }
        return answer;
    }
}