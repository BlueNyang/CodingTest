import "sort"

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func solution(numbers []int) int {
    // 원본 슬라이스 훼손 방지
    res := make([]int, len(numbers))
    copy(res, numbers)
    
    sort.Ints(res)
    
    l := len(res)
    
    a := res[0] * res[1]
    b := res[l - 1] * res[l - 2]
    
    return max(a, b)
}