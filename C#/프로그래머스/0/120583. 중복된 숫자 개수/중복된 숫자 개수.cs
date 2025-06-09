using System;

public class Solution {
    public int solution(int[] array, int n) {
        int answer = 0;
        
        foreach(var a in array)
            if (a == n) answer++;
        
        return answer;
    }
}