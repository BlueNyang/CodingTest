func solution(strlist []string) []int {
    res := make([]int, 0, len(strlist))
    
    for _, str := range strlist {
        res = append(res, len(str))
    }
    
    return res
}