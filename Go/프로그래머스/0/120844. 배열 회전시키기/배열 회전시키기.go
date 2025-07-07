func solution(numbers []int, direction string) []int {
    if direction == "left" {
        return append(numbers[1:], numbers[0])
    } else {
        idx := len(numbers) - 1
        return append([]int{numbers[idx]}, numbers[:idx]...)
    }
}