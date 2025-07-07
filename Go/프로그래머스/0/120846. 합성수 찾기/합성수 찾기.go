func is_prime(n int) bool {
    num := n
    for i := 2; i < n; i++ {
        for num % i == 0 {
            num /= i
        }
    }
    return num > 1
}

func solution(n int) int {
    count := 0
    
    for i := 2; i <= n; i++ {
        if !is_prime(i) {
            count++
        }
    }
    
    return count
}