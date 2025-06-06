func solution(balls int, share int) int64 {
    var answer int64 = 1
    for i := 0; i < share; i++ {
        answer *= int64(balls - i)
        answer /= int64(i + 1)
    }
    return answer
}