class Solution {
    val NUM_RESULT = 5
    
    fun solution(num_list: IntArray): IntArray {
        var n_list = num_list.copyOf()
        var answer = IntArray(NUM_RESULT)
        
        for (i in 0 until NUM_RESULT) {
            var min_idx: Int = i
            for (j in i until n_list.size) {
                if (n_list[min_idx] > n_list[j]) {
                    min_idx = j
                }
            }
            if (i != min_idx) {
                n_list [i] = n_list[min_idx].also {
                    n_list[min_idx] = n_list[i]
                }
            }
            answer[i] = n_list[i]
        }
        return answer
    }
}