import (
    "strings"
    "strconv"
)

type Polynomial struct {
    x, c int
}

func (p *Polynomial) ToString() string {
    res := strings.Builder{}
    
    if p.x > 1 {
        res.WriteString(strconv.Itoa(p.x))
    }
    
    if p.x != 0 {
        res.WriteString("x")
    }
    
    if p.x != 0 && p.c != 0 {
        res.WriteString(" + ")
    }
    
    if p.c != 0 {
        res.WriteString(strconv.Itoa(p.c))
    }
    
    return res.String()
}

func (p *Polynomial) getFromString(s string) {
    if s == "x" {
        p.x++
    } else if s[len(s)-1] == 'x' {
        n := string(s[:len(s)-1])
        p.x += StoInt(n)
    } else {
        p.c += StoInt(s)
    }
}

func StoInt(s string) int {
    if num, err := strconv.Atoi(s); err == nil {
        return num
    }
    return 0
}

func solution(polynomial string) string {
    tokens := strings.Split(polynomial, " + ")
    poly := Polynomial {}
    
    for _, token := range tokens {
        poly.getFromString(token)
    }
    
    return poly.ToString()
}