import math

def solution(numer1, denom1, numer2, denom2):
    n = numer1 * denom2 + numer2 * denom1
    d = denom1 * denom2
    
    cd = math.gcd(n, d)
    
    n = n // cd
    d = d // cd
    
    answer = [n, d]
    
    return answer