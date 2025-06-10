import "sort"

func solution(array []int) int {
    // array 원본 훼손 방지
    arr := make([]int, len(array))
    copy(arr, array)
    
    sort.Ints(arr)
    
    return arr[len(arr) / 2]
}