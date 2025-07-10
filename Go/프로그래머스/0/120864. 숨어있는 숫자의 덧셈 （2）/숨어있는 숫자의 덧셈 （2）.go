func solution(my_string string) int {
    var res, temp int
    
    my_string += "a"
    for _, r := range my_string {
        if r >= '0' && r <= '9' {
            temp *= 10
            temp += int(r - '0')
        } else if temp != 0 {
            res += temp
            temp = 0
        }
    }
    
    return res
}