import "strings"

var morse = map[string]string {
	".-": "a", "-...": "b", "-.-.": "c", "-..": "d", ".": "e", "..-.": "f", 
	"--.": "g", "....": "h", "..": "i", ".---": "j", "-.-": "k", ".-..": "l", 
	"--": "m", "-.": "n", "---": "o", ".--.": "p", "--.-": "q", ".-.": "r", 
	"...": "s", "-": "t", "..-": "u", "...-": "v", ".--": "w", "-..-": "x", 
	"-.--": "y", "--..": "z",
}

func solution(letter string) string {
    words := strings.Split(letter, " ")
    
    var answer strings.Builder
    
    for _, word := range words {
        converted := morse[word]
        answer.WriteString(converted)
    }
    
    return answer.String()
}