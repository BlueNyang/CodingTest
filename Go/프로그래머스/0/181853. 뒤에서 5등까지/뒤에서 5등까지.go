var NUM_RESULT = 5

func solution(num_list []int) []int {
    // Go는 포인터를 전달하므로, 원본을 유지하기 위해 복사하여 사용함.
    n_list := make([]int, len(num_list))
    result := make([]int, NUM_RESULT)
    copy(n_list, num_list)
    
    // 선택 정렬을 NUM_RESULT(5)번만 수행
    for i := 0; i < NUM_RESULT; i++ {
        min_idx := i
        for j := i; j < len(n_list); j++ {
            if n_list[min_idx] > n_list[j] {
                min_idx = j
            }
        }
        if i != min_idx {
            n_list[min_idx], n_list[i] = n_list[i], n_list[min_idx]
        }
    }
    
    copy(result, n_list)
    
    return result
}