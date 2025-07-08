func solution(my_string string) int {
    res := 0
    
    for _, r := range my_string {
        if r >= '0' && r <='9' {
            res += int(r - '0')
        }
    }
    
    return res
}