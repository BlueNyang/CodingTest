const jokaBabb = ["aya", "ye", "woo", "ma"];

function checkCanSpeak(word) {
    for (const j of jokaBabb) {
        if (word.length == 0)
            return true;
        if (word.startsWith(j))
            return checkCanSpeak(word.substring(j.length));
    }
    return false
}

function solution(babbling) {
    let answer = 0;
    babbling.forEach((b) => {
        if (checkCanSpeak(b)){
            answer += 1;
        }
    })
    return answer;
}