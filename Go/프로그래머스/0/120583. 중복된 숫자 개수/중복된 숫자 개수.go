func solution(array []int, n int) int {
    count := 0
    for _, a := range array {
        if a == n {
            count++
        }
    }
    
    return count
}