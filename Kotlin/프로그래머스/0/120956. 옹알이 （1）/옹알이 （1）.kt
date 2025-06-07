class Solution {
    var jokaBabb: Array<String> = arrayOf("aya", "ye", "woo", "ma")
    
    fun canSpeak(word: String): Boolean {
        for (j in jokaBabb) {
            if (word.length == 0){
                return true
            }
            if (word.startsWith(j)) {
                return canSpeak(word.substring(j.length))
            }
        }
        return false
    }
    
    fun solution(babbling: Array<String>): Int {
        var answer: Int = 0
        for (b in babbling) {
            if (canSpeak(b)) {
                answer += 1
            }
        }
        return answer
    }
}