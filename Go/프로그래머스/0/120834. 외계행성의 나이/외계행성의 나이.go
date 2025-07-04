func solution(age int) string {
    // preallocate
    var count int
    for i := 1; i < age; i *= 10 {
        count++
    }
    
    // 기준값
    const STDV = rune('a')
    // result
    res := make([]rune, 0, count)
    
    for i := age; i > 0; i /= 10 {
        num := rune(i % 10) + STDV
        res = append([]rune{num}, res...)
    }
    
    return string(res)
}