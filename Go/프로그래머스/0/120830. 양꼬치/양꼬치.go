func solution(n int, k int) int {
    const SKEWERS_PRICE int = 12000;
    const DRINK_PRICE int = 2000;
    
    return SKEWERS_PRICE * n + (k - n / 10) * DRINK_PRICE
}