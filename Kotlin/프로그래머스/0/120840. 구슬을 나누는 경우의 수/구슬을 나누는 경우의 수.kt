class Solution {
    fun solution(balls: Int, share: Int): Long {
        var answer: Long = 1
        
        for(i in 0 until share) {
            answer *= (balls - i)
            answer /= (i + 1)
        }
        
        return answer
    }
}