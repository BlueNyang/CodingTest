class Solution {
    fun solution(num1: Int, num2: Int): Int {
        val res = num1.toDouble() / num2
        return (res * 1000).toInt()
    }
}