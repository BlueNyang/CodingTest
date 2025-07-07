func solution(num_list []int, n int) [][]int {
    res := make([][]int, len(num_list) / n)
    
    row := -1
    for i, v := range num_list {
        if i % n == 0 {
            row++
            res[row] = make([]int, 0, n)
        }
        
        res[row] = append(res[row], v)
    }
    
    return res
}