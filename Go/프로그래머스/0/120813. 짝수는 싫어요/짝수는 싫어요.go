func solution(n int) []int {
    result := make([]int, 0, (n + 1) / 2)
    
    for i := 1; i <= n; i += 2 {
        result = append(result, i)
    }
    
    return result
}