func solution(num_list []int) []int {
    res := []int{0, 0}
    
    for _, v := range num_list {
        if v % 2 == 0 {
            res[0]++
        } else {
            res[1]++
        }
    }
    
    return res
}