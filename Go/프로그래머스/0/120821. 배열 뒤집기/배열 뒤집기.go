func solution(num_list []int) []int {
    result := make([]int, 0, len(num_list))
    
    for i := len(num_list); i > 0; i-- {
        result = append(result, num_list[i - 1])
    }
    return result
}