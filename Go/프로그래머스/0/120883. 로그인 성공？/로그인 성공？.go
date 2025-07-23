func solution(id_pw []string, db [][]string) string {
    for _, account := range db {
        if id_pw[0] == account[0] {
            if id_pw[1] == account[1] {
                return "login"
            }
            return "wrong pw"
        }
    }
    return "fail"
}