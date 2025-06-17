#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int a = n % 2 == 0 ? n : n - 1;
    return a * (a + 2) / 4;
}