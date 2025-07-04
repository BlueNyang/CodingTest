func solution(price int) int {
    var temp_price float32
    
    switch v := price / 100000; {
        case v > 4:
            temp_price = float32(price) * 0.8
        case v > 2:
            temp_price = float32(price) * 0.9
        case v > 0:
            temp_price = float32(price) * 0.95
        default:
            temp_price = float32(price)
    }
    
    return int(temp_price)
}