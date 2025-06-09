import java.util.Arrays;

class Solution {
    private int NUM_RESULT = 5;
    
    public int[] solution(int[] num_list) {
        // 원본 배열의 변경 방지
        int[] n_list = num_list.clone();
        
        for (int i = 0; i < NUM_RESULT; i++) {
            int min_idx = i;
            for (int j = i; j < n_list.length; j++) {
                if (n_list[min_idx] > n_list[j]) {
                    min_idx = j;
                }
            }
            if (i != min_idx) {
                int temp = n_list[i];
                n_list[i] = n_list[min_idx];
                n_list[min_idx] = temp;
            }
        }
        int[] answer = Arrays.copyOfRange(n_list, 0, NUM_RESULT);
        
        return answer;
    }
}