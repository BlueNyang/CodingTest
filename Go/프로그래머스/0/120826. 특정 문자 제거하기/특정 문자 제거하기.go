func solution(my_string string, letter string) string {
    target := []rune(letter)[0]
    
    newLen := len(my_string)
    for _, r := range my_string {
        if r == target {
            newLen--
        }
    }
    
    res := make([]rune, 0, newLen)
    
    for _, r := range my_string {
        if r != target {
            res = append(res, r)
        }
    }
    
    return string(res)
}