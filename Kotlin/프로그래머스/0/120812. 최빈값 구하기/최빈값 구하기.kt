class Solution {
    fun solution(array: IntArray): Int {
        // 숫자별로 그룹화 하고, 그룹 사이즈를 Map의 value로 반환
        val counts = array.groupBy{ it }
                          .mapValues { it.value.size }
        
        // MaxCount는 Map의 Value중 max 값
        var maxCount: Int = counts.values.maxOrNull() ?: 0
        // List로 필터링
        val answer = counts.filterValues { it == maxCount }
                           .keys
                           .toList()
        
        // List의 길이가 2개(최댓값으로 필터링한 값)
        if (answer.size > 1) return -1
        // 아니면 첫번째 값(1개밖에 없음)
        return answer[0]
    }
}