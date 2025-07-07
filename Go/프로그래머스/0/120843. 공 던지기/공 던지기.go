func solution(numbers []int, k int) int {
    return numbers[(k - 1) * 2 % len(numbers)]
}