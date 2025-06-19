using namespace std;

int solution(int n) {
    int answer;
    int fac_i = 1;
    
    for (answer = 2; fac_i <= n; ++answer) {
        fac_i *= answer;
    }
    
    return answer - 2;
}