func solution(rsp string) string {
    res := make([]rune, 0, len(rsp))
    
    for _, r := range rsp {
        switch r {
            case '0':
                res = append(res, '5')
            case '2':
                res = append(res, '0')
            case '5':
                res = append(res, '2')
            default:
        }
    }
    return string(res)
}