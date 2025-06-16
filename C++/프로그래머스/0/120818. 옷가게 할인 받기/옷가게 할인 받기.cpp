using namespace std;

int solution(int price) {
    int p = price / 100000;
    if (p > 4) return (int)(price * 0.8);
    if (p > 2) return (int)(price * 0.9);
    if (p > 0) return (int)(price * 0.95);
    return price;
}