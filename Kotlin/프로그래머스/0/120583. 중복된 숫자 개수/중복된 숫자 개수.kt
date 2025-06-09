class Solution {
    fun solution(array: IntArray, n: Int): Int {
        var answer: Int = 0
        
        for (a in array) {
            if (a == n) answer++
        }
        
        return answer
    }
}