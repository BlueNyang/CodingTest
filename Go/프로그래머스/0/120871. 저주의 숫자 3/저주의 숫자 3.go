func Check3 (n int) bool {
    for ;n > 0; n /= 10 {
        if n % 10 == 3 {
            return true
        }
    }
    return false
}

func solution(n int) int {
    for p := 1; p <= n; p++ {
        if p % 3 == 0 || Check3(p) {
            n++
        }
    }
    return n
}