using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solution(int n) {
    return n / gcd(6, n);
}