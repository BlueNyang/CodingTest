func solution(keyinput []string, board []int) []int {
    x_max := board[0] / 2
    x_min := -board[0] / 2
    y_max := board[1] / 2
    y_min := -board[1] / 2
    
    pos := make([]int, 2)
    
    for _, key := range keyinput {
        switch {
        case key == "right" && pos[0] < x_max:
            pos[0]++
        case key == "left" && pos[0] > x_min:
            pos[0]--
        case key == "up" && pos[1] < y_max:
            pos[1]++
        case key == "down" && pos[1] > y_min:
            pos[1]--
        }
    }
    
    
    return pos
}