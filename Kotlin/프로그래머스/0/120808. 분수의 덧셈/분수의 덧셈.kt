class Solution {
    fun gcdRecursive(a: Int, b: Int): Int {
        return if (b == 0) a else gcdRecursive(b, a % b)
    }
    
    fun solution(numer1: Int, denom1: Int, numer2: Int, denom2: Int): IntArray {
        
        var numer = numer1 * denom2 + numer2 * denom1
        var denom = denom1 * denom2
        
        val gcd = gcdRecursive(numer, denom)
        
        numer /= gcd
        denom /= gcd
        
        val answer = intArrayOf(numer, denom)
        return answer
    }
}