import "strings"


var jokaBabb = []string{"aya", "ye", "woo", "ma"}

func checkCanSpeak(word string) bool {
    if len(word) == 0 {
        return true
    }
    for _, j := range jokaBabb {
        if strings.HasPrefix(word, j) {
            remainWord := word[len(j):]
            if checkCanSpeak(remainWord) {
                return true
            }
        }
    }
    return false
}

func solution(babbling []string) int {
    count := 0
    for _, b := range babbling {
        if checkCanSpeak(b) {
            count += 1
        }
    }
    return count
}