import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] array) {
        Map<Integer, Long> counts = Arrays.stream(array)
            .boxed()
            .collect(
            Collectors.groupingBy(x -> x, Collectors.counting())
        );
        
        int answer = 0;
        long maxCount = 0;
        
        for(Map.Entry<Integer, Long> c: counts.entrySet()) {
            if (c.getValue() == maxCount) answer = -1;
            if (c.getValue() > maxCount) {
                answer = c.getKey();
                maxCount = c.getValue();
            }
        }
        
        return answer;
    }
}