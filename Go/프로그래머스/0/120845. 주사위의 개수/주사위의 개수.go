func solution(box []int, n int) int {
    res := 1
    for _, v := range box {
        res *= v / n
    }
    
    return res
}