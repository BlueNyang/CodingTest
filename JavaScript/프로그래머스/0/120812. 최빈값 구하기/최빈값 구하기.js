function solution(array) {
    const counts = new Map();
    array.forEach(a => {
        counts.set(a, (counts.get(a) || 0) + 1);
    });
    
    let a_num = 0;
    let maxCount = 0;
    
    counts.forEach((value, key) => {
        if (value == maxCount) a_num = -1;
        if (value > maxCount) {
            a_num = key;
            maxCount = value;
        }
    })
    
    const answer = a_num;
    return answer;
}