func GetGCD(a, b int) int {
    for b > 0 {
        a, b = b, a % b
    }
    
    return a
}

func solution(a, b int) int {
    b /= GetGCD(a, b)
    
    for b % 2 == 0 {
        b /= 2
    }
    
    for b % 5 == 0 {
        b /= 5
    }
    
    if b == 1 {
        return 1
    }
    return 2
}