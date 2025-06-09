func solution(num1 int, num2 int) int {
    res := float64(num1) / float64(num2)
    return int(res * 1000)
}