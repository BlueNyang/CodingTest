class Solution {
    fun solution(array: IntArray, height: Int): Int {
        var answer: Int = 0
        
        array.forEach { a ->
            if (a > height) answer++
        }
        
        return answer
    }
}