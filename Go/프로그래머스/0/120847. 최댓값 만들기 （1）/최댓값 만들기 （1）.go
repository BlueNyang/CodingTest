import "sort"

func solution(numbers []int) int {
    sort.Slice(numbers, func(i, j int) bool {
        return numbers[i] > numbers[j]
    })
    
    
    return numbers[0] * numbers[1]
}