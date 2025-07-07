func solution(n int) int {
    res, i := 1, 2
    
    for ; res <= n; i++ {
        res *= i
    }
    
    return i - 2
}