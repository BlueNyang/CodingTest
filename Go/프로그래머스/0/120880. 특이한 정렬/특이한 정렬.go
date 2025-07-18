import "sort"

func Distance(num, std int) int {
    n := std - num
    if n < 0 {
        return -n
    }
    return n
}

func solution(numlist []int, n int) []int {
    copied := make([]int, len(numlist))
    copy(copied, numlist)
    
    sort.Slice(copied, func(i, j int) bool {
        a := Distance(copied[i], n)
        b := Distance(copied[j], n)
        if a == b {
            return copied[i] > copied[j]
        } else {
            return a < b
        }
    })
    
    return copied
}