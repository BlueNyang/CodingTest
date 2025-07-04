import "sort"

// 환자 정보를 저장하는 구조체
type Patient struct {
    // 응급도와 index
    Emer, Idx int
}

func solution(emergency []int) []int {
    // 환자 목록
    patients := make([]Patient, 0, len(emergency))
    
    // 목록에 추가
    for i, v := range emergency {
        patients = append(patients, Patient{v, i})
    }
    
    // 응급도 순으로 정렬
    sort.Slice(patients, func(i, j int) bool {
        return patients[i].Emer > patients[j].Emer
    })
    
    // 결과 슬라이스
    res := make([]int, len(emergency))
    
    // 환자의 인덱스에 진료 순서 할당
    for i, v := range patients {
        res[v.Idx] = i + 1
    }
    
    return res
}