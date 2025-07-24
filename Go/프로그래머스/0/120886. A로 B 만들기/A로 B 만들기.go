func solution(before string, after string) int {
    chars := make([]rune, 26)
    
    var s_rune rune = 'a'
    
    for _, r := range before {
        chars[r-s_rune]++
    }
    
    for _, r := range after {
        chars[r-s_rune]--
    }
    
    for _, v := range chars {
        if v != 0 {
            return 0
        }
    }
    
    return 1
}