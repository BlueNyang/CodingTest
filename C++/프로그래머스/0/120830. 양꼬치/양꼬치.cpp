#include <string>

using namespace std;

const int SKEWERS_PRICE = 12000;
const int DRINK_PRICE = 2000;

int solution(int n, int k) {
    return n * SKEWERS_PRICE + (k - n / 10) * DRINK_PRICE;
}