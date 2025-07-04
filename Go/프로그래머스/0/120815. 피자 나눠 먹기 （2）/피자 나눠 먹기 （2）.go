func getGCD(a, b int) int {
    for b != 0 {
        a, b = b, a % b
    }
    
    return a
}

func solution(n int) int {
    return n / getGCD(6, n)
}