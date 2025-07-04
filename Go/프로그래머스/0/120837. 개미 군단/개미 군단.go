func solution(hp int) int {
    ants := []int {5, 3, 1}
    
    var res int
    
    for _, v := range ants {
        res += hp / v
        hp %= v
    }
    
    
    return res
}