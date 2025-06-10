func solution(numbers []int) []int {
    result := make([]int, len(numbers))
    
    for i, v := range numbers {
        result[i] = v << 1
    }
    
    return result
}