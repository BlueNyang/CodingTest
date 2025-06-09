func solution(array []int, height int) int {
    answer := 0
    for _, v := range array {
        if v > height {
            answer++
        }
    }
    
    return answer
}