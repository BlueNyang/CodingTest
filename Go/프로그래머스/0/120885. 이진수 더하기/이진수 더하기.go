import "strconv"

func solution(bin1 string, bin2 string) string {
    num1, err := strconv.ParseInt(bin1, 2, 64)
    if err != nil {
        panic(err)
    }
    num2, err := strconv.ParseInt(bin2, 2, 64)
    if err != nil {
        panic(err)
    }
    
    res := num1 + num2
    
    return strconv.FormatInt(res, 2)
}