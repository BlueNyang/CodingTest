import "strings"

func solution(spell []string, dic []string) int {
    found := false
    
    for _, word := range dic {
        for _, s := range spell {
            if strings.Count(word, s) != 1 {
                found = false
                break
            }
            found = true
        }
        if found {
            return 1
        }
    }
    
    return 2
}