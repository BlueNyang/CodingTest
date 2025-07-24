func DigitDp(n, k int) int {
    if n < 0 {
        return 0
    }
    
    count := 0
    
    for weight := 1; weight <= n; weight *= 10 {
        higherPart := n / (weight * 10)
        currentPart := (n / weight) % 10
        lowerPart := n % weight
        
        count += higherPart * weight
        
        if currentPart > k {
            count += weight
        } else if currentPart == k {
            count += lowerPart + 1
        }
    
        if k == 0 {
            count -= weight
        }
    }
    
    return count
}

func solution(i, j, k int) int {
    return DigitDp(j, k) - DigitDp(i - 1, k)
}