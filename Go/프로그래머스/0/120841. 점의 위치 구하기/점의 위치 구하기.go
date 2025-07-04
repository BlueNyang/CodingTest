func solution(dot []int) int {
    var res int
    
    // 1,2 분면과 3,4 분면으로 분리
    if dot[1] > 0 {
        res = 1
    } else {
        res = 3
    }
    
    // x * y가 양수면 1,3분면, 음수면 2,4분면
    if dot[1] * dot[0] < 0 {
        res++
    }
    return res
}