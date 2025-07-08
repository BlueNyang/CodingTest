import "sort"

func solution(my_string string) []int {
    res := make([]int, 0)
    
    for _, r := range my_string {
        if r >= '0' && r <= '9' {
            res = append(res, int(r - '0'))
        }
    }
    
    sort.Ints(res)
    
    return res
}