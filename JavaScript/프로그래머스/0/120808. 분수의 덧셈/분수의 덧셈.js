function getGCD (a, b) {
    //a, b는 0 ~ 1000 이므로 abs를 할 필요가 없음
    return b == 0 ? a : getGCD(b, a % b);
}

function solution(numer1, denom1, numer2, denom2) {
    const numer = numer1 * denom2 + numer2 * denom1;
    const denom = denom1 * denom2;
    
    const gcd = getGCD(numer, denom);
    
    const answer = [numer / gcd, denom / gcd];
    return answer;
}