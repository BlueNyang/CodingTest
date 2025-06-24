#include <string>
#include <vector>

using namespace std;

/* -- 해당 코드에서 사용한 접근법 --
 * 해당 코드에서는 각 자릿수 별 k 등장 횟수를 구하고,
 * 0 ~ j까지의 카운트에서 0 ~ i 카운트를 뺴는 방식
 * 숫자를 문자열 변환 후 탐색을 하는 것보다 압도적으로 적은 연산을 수행
 * i = 1, j = 100,000 이더라도 for 문은 6번,
 * 내부 사칙 연산은 약 10번으로 최악의 경우에도 약 60번만 연산
 */

// 0 ~ N까지의 k 등장 횟수
// n은 0이상, k는 그대로 전달
int digit_dp(int n, int k) {
    if (n < 0) return 0;
    
    // 100,000 이하 이므로 int 사용
    int count = 0;
    
    // 자릿수별 k등장 횟수 계산
    for (int weight = 1; weight <= n; weight *= 10) {
        // 현재 자릿수보다 큰 부분
        int higher_part = n / (weight * 10);
        // 현재 자릿수 숫자
        int current_digit = (n / weight) % 10;
        // 현재 자릿수 보다 작은 부분
        int lower_part = n % weight;
        
        // 현재 자릿수에서는 k가 큰 부분 이상 만큼 등장
        // 예를 들어 12345에서 100의 자릿수 이상만 본다면
        // k가 1일 때, 100의 자리가 1인 경우는 1200번 + a
        // 0100 ~ 0199, 1100 ~ 1199, ... 11100 ~ 11199
        count += higher_part * weight;
        
        // 현재 자릿수가 k보다 크면 추가
        // 위의 예시에서 12100 ~ 12199의 경우를 추가
        if (current_digit > k) count += weight;
        
        // 현재 자릿수가 k이면
        // 하위 자릿수 만큼만 추가
        // 위의 예시에서 k가 3이면 12300 ~ 12345까지만 추가
        if (current_digit == k) count += lower_part + 1;
        
        // k가 0인 경우 잘못 세어진 횟수 제거
        if (k == 0) {
            count -= weight;
        }

    }        
    return count;
}

int solution(int i, int j, int k) {
    // j까지 횟수에서 i까지 횟수 빼기
    return digit_dp(j, k) - digit_dp(i - 1, k);
}