const NUM_RESULT = 5;

function solution(numList) {
    let nList = [...numList];
    let answer = [];
    
    for(let i = 0; i < NUM_RESULT; i++) {
        let minIdx = 0;
        
        nList.forEach((n, j) => {
            if (nList[minIdx] > n) minIdx = j;
        })
        
        answer = [...answer, nList[minIdx]];
        nList.splice(minIdx, 1);
    }
    
    return answer;
}