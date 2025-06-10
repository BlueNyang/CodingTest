import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = IntStream.of(numbers)
                                .map(x -> x * 2)
                                .toArray();
        return answer;
    }
}