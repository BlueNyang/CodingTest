func solution(numbers []int) float64 {
    total := 0.0
    
    for _, v := range numbers {
        total += float64(v)
    }
    
    total /= float64(len(numbers))
    return total
}