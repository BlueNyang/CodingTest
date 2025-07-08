import (
    "strings"
    "strconv"
)

func solution(s string) int {
    token := strings.Fields(s)
    sum := 0
    prev := 0
    
    for _, v := range token {
        if v == "Z" {
            sum -= prev
        } else {
            num, err := strconv.Atoi(v)
            
            if err != nil {
                // 에러처리
                continue
            }
            
            sum += num
            prev = num
        }
    }
    
    return sum
}