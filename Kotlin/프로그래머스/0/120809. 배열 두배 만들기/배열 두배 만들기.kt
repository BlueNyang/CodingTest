class Solution {
    fun solution(numbers: IntArray): IntArray {
        val answer: IntArray = numbers
            .map{ it * 2 }
            .toIntArray()
        return answer
    }
}