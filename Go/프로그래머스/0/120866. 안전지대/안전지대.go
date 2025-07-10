// (x, y) 주변을 위험 지역으로 표기하고 표기한 칸수 반환
func CheckDanger(b [][]int, x, y int) int {
    // 현재 칸 포함
    count := 1
    
    // x, y의 최댓값
    n := len(b)
    for r := y-1; r <= y+1; r++ {
        for c := x-1; c <= x+1; c++ {
            // 좌표가 최대/최소 내에 있고, 0으로 표기되어 있으면
            if r > -1 && r < n && c > -1 && c < n && b[r][c] == 0 {
                // 위험 지역 처리 후 count++
                b[r][c] = -1
                count++
            }
        }
    }
    
    return count
}

func solution(board [][]int) int {
    res := len(board) * len(board[0])
    
    // 원본 슬라이스 훼손 방지를 위한 복사
    c_board := make([][]int, len(board))
    
    for i, row := range board {
        c_row := make([]int, len(row))
        copy(c_row, row)
        c_board[i] = c_row
    }
    
    for y, row := range c_board {
        for x, v := range row {
            if v == 1 {
                res -= CheckDanger(c_board, x, y)
            }
        }
    }
    
    return res
}