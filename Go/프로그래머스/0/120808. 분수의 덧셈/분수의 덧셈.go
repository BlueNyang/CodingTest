func getGCD(a int, b int) int {
    if b == 0 {
        return a
    }
    return getGCD(b, a % b)
}

func solution(numer1 int, denom1 int, numer2 int, denom2 int) []int {
    numer := numer1 * denom2 + numer2 * denom1
    denom := denom1 * denom2
    
    gcd := getGCD(numer, denom)
    
    return []int{numer / gcd, denom / gcd}
}