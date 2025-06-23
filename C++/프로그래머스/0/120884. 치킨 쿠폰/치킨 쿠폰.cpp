#include <iostream>

using namespace std;

// chicken == 쿠폰 수
int solution(int chicken) {
    // 쿠폰이 10개가 안되면 0반환
    if (chicken < 10) return 0;
    
    // 서비스 치킨은 쿠폰 10장 당 1개
    int sv_chicken = chicken / 10;
    
    // 서비스 먹은 후 쿠폰 = 서비스 치킨 + 남은 쿠폰
    int r_coupon = sv_chicken + chicken % 10;
    
    // 쿠폰으로 서비스 치킨이 안나올 때까지 재귀
    return sv_chicken + solution(r_coupon);
}