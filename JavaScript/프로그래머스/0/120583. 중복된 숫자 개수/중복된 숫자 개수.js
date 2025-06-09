function solution(array, n) {
    var answer = 0;
    
    array.forEach((a) => {
        if (a == n) answer += 1;
    });
    
    return answer;
}