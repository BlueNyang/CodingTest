func GetTilt(p1, p2 []int) []int {
    return []int{p2[0] - p1[0], p2[1] - p1[1]}
}

func solution(dots [][]int) int {
    lines := [][]int{
        {0, 1}, {0, 2}, {0, 3},
        {1, 2}, {1, 3}, {2, 3},
    }
    
    tilts := make([][]int, 0, 6)
    
    for _, l := range lines {
        tilts = append(tilts, GetTilt(dots[l[0]], dots[l[1]]))
    }
    
    // 0-1|2-3, 0-2|1-3, 0-3|1-2
    // 0|5, 1|4, 2|3
    // dx1:dy1 = dx2:dy2 => dx1 * dy2 = dy1 * dx2
    for i, t := range tilts {
        ratio1 := t[0] * tilts[5-i][1]
        ratio2 := t[1] * tilts[5-i][0]
        if ratio1 == ratio2 {
            return 1
        }
    }
    return 0
}