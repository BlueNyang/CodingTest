using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] array) {
        // Dictionary 생성
        Dictionary<int, int> counts = new Dictionary<int, int>();
        
        // foreach로 숫자 갯수 카운트
        foreach(var a in array) {
            if (!counts.ContainsKey(a))
                counts.Add(a, 0);
            counts[a]++;
        }
        
        // 기본값 초기화
        int answer = -1;
        int maxValue = 0;
        
        // foreach로 최빈값 탐색
        foreach(var c in counts) {
            // 같은 카운트의 수가 있으면 -1
            if (c.Value == maxValue) answer = -1;
            // maxValue 찾기
            if (c.Value > maxValue) {
                maxValue = c.Value;
                answer = c.Key;
            }
        }
        
        return answer;
    }
}