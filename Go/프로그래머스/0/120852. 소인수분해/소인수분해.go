func solution(n int) []int {
    res := make([]int, 0)
    
    num := n
    for i := 2; i * i <= n; i++ {
        if num % i == 0 {
            res = append(res, i)
        }
        for num % i == 0 {
            num /= i
        }
    }
    
    if num > 1 {
        res = append(res, num)
    }
    
    return res
}