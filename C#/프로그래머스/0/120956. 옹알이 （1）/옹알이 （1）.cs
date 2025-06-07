using System;
using System.Collections.Generic;

public class Solution {
    List<string> jokaBabb = new List<string>() { "aya", "ye", "woo", "ma" };
    
    private bool checkCanSpeak(string word) {
        if (word.Length == 0) return true;
        foreach(var j in jokaBabb) {
            if (word.StartsWith(j)) {
                return checkCanSpeak(word.Substring(j.Length));
            }
        }
        return false;
    }
    
    public int solution(string[] babbling) {
        int answer = 0;
        foreach(var b in babbling) {
            if (checkCanSpeak(b)) answer++;
        }
        return answer;
    }
}