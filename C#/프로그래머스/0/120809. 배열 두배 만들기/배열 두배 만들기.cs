using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] numbers) {
        return numbers.Select(x => x << 1).ToArray();
    }
}