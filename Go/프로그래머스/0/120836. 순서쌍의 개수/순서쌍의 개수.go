func primeFactorisation(n int) map[int]int {
    factors := make(map[int]int)
    
    for i := 2; i * i <= n; i++ {
        for n % i == 0 {
            n /= i
            factors[i]++
        }
    }
    
    if n != 1 {
        factors[n]++
    }
    
    return factors
}

func solution(n int) int {
    factors := primeFactorisation(n)
    
    res := 1
    
    for _, v := range factors {
        res *= v + 1
    }
    
    return res
}