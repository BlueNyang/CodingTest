import "sort"

type Student struct {
    Idx int
    Avg float32
}

func solution(score [][]int) []int {
    students := make([]Student, 0, len(score))
    
    for i, v := range score {
        avg := float32(v[0] + v[1]) / 2
        students = append(students, Student{Idx: i, Avg: avg})
    }
    
    sort.Slice(students, func (i, j int) bool {
        return students[i].Avg > students[j].Avg
    })
    
    res := make([]int, len(score))
    
    for i, s := range students {
        if i == 0 {
            res[s.Idx] = 1
            continue
        } else if s.Avg == students[i-1].Avg {
            res[s.Idx] = res[students[i-1].Idx]
        } else {
            res[s.Idx] = i + 1
        }
    }
    
    return res
}