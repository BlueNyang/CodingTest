import (
    "strings"
    "strconv"
)

func solution(polynomial string) string {
    tokens := strings.Fields(polynomial)
    var x1, c int
    
    for _, token := range tokens {
        if token == "+" {
            continue
        }
        
        if token == "x" {
            x1++
        } else if token[len(token)-1] == 'x' {
            num, _ := strconv.Atoi(token[:len(token)-1])
            x1 += num
        } else {
            num, _ := strconv.Atoi(token)
            c += num
        }
    }
    
    res := strings.Builder{}
    
    if x1 == 1 {
        res.WriteString("x")
    } else if x1 > 0 {
        res.WriteString(strconv.Itoa(x1))
        res.WriteString("x")
    }
    
    if c != 0 {
        if x1 > 0 {
            res.WriteString(" + ")
        }
        res.WriteString(strconv.Itoa(c))
    }
    
    return res.String()
}