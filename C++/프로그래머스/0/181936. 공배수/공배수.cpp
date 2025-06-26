int solution(int number, int n, int m) {
    return static_cast<int>(number % n == 0 && number % m == 0);
}