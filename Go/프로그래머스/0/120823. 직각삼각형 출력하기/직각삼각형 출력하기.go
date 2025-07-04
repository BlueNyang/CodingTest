package main

import "fmt"

type MyInt int32

func (n MyInt) PrintStar() {
    // 문자 수 = n(n+1)/2, 개행문자 수 = n - 1
    size := (n * (n + 1) / 2) + (n - 1)
    var runes = make([]rune, 0, int(size));
    
    for i := 0; i < int(n); i++ {
        for j := 0; j <= i; j++ {
            runes = append(runes, '*')
        }
        if i < int(n - 1) {
            runes = append(runes, '\n')
        }
    }
    
    fmt.Println(string(runes))
}

func main() {
    var n int
    fmt.Scan(&n)
    //fmt.Println(n)
    MyInt(n).PrintStar()
}