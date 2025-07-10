func IntAbs(n int) int {
    if n < 0 {
        return -n
    }
    return n
}

func solution(sides []int) int {
    // sides의 2개 선분 사이의 숫자 수
    diff := IntAbs(sides[0] - sides[1])
    // 2개 선분의 길이보다 1작은 값까지의 갯수 - 2개 사이 숫자 수
    return sides[0] + sides[1] - 1 - diff
}