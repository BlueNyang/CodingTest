func solution(my_string string) string {
    vowels := map[rune]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
    
    var res []rune
    
    for _, r := range my_string {
        if !vowels[r] {
            res = append(res, r)
        }
    }
    return string(res)
}