using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    private int COUNT_RESULT = 5;
    // num_list의 원소가 겹치지 않는다는 보장(제한조건)이 없음
    // 정렬을 수정하거나, 원소를 지워나가는 방식으로 해야 함.
    public int[] solution(int[] num_list) {
        
        List<int> n_list = num_list.ToList();
        int[] answer = new int[COUNT_RESULT];
        
        for(int i = 0; i < COUNT_RESULT; i++) {
            int min_idx = 0;
            for(int j = 0; j < n_list.Count; j++) {
                if (n_list[min_idx] > n_list[j]) {
                    min_idx = j;
                }
            }
            answer[i] = n_list[min_idx];
            n_list.RemoveAt(min_idx);
        }
        
        return answer;
    }
}