func solution(n int) int {
    var res int = n
    if n % 2 == 1 { res--; }
    return res * (res + 2) / 4
}