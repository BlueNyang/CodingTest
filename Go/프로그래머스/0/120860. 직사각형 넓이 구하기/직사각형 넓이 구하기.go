func AbsInt(n int) int {
    if n < 0 {
        return -n
    }
    return n
}

func solution(dots [][]int) int {
    w, h := dots[0][0], dots[0][1]
    
    
    if w != dots[1][0] {
        w = AbsInt(w - dots[1][0])
    } else {
        w = AbsInt(w - dots[2][0])
    }
    
    if h != dots[1][1] {
        h = AbsInt(h - dots[1][1])
    } else {
        h = AbsInt(h - dots[2][1])
    }
    
    return w * h
}