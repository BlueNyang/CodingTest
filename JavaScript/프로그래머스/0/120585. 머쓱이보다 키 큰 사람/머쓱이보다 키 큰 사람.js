function solution(array, height) {
    var answer = 0;
    
    array.forEach((a) => {
        a > height ? answer++ : 0;
    })
    
    return answer;
}