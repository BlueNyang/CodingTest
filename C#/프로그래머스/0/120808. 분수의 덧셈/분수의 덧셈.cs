using System;

public class Solution {
    internal int getGCD(int a, int b) {
        return b == 0 ? a : getGCD(b, a % b);
    }
    
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int numer = numer1 * denom2 + numer2 * denom1;
        int denom = denom1 * denom2;
        
        int gcd = getGCD(numer, denom);
        
        return new int[] {numer / gcd, denom / gcd};
    }
}