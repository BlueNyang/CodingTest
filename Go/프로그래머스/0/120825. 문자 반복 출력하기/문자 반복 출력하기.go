func solution(my_string string, n int) string {
    res := make([]rune, 0, len(my_string) * n)
    
    for _, v := range my_string {
        for i := 0; i < n; i++ {
            res = append(res, v)
        }
    }
    
    return string(res)
}