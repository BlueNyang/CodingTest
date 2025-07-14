func solution(lines [][]int) int {
    line_map := make([]int, 200)
    
    for _, l := range lines {
        for i := l[0]; i < l[1]; i++ {
            line_map[i+100]++
        }
    }
    
    answer := 0
    for _, v := range line_map {
        if v > 1 {
            answer++
        }
    }
    return answer
}