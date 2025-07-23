func solution(chicken int) int {
    if chicken < 10 {
        return 0
    }
    
    sv_chicken := chicken / 10
    
    remain_coupon := sv_chicken + chicken % 10
    
    return sv_chicken + solution(remain_coupon)
}