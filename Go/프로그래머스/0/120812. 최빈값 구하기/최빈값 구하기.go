func solution(array []int) int {
    // make map
    counts := make(map[int]int)
    
    // counting
    for _, v := range array {
        counts[v]++
    }
    
    // init values
    answer := -1
    maxValue := 0
    
    // search mode
    for n, v := range counts {
        if maxValue == v {
            answer = -1
        }
        if v > maxValue {
            maxValue = v
            answer = n
        }
    }
    
    return answer
}