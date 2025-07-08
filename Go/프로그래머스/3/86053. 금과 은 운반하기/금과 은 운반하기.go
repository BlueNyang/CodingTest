// min() 함수
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// 주어진 시간 내에 필요한 금과 은을 운반할 수 있는지 확인하는 함수
func checkCanDeliver(ticks int64, needGold, needSilver int, g, s, w, t []int) bool {
	// int64로 변환
	nG := int64(needGold)
	nS := int64(needSilver)

	// 전체 운반 가능한 금, 은, 총량을 계산
	total_carried_gold := int64(0)
	total_carried_silver := int64(0)
	total_carried := int64(0)

	// 각 트럭에 대해 운반 가능한 금, 은, 총량을 계산
	for i, v := range t {
		// 각 트럭이 왕복하는 데 걸리는 시간
        move_time := 2 * int64(v)
		// 해당 트럭이 주어진 시간 내에 몇 번 왕복할 수 있는지 계산
		moves := ticks / move_time
        
		// 만약 왕복 횟수가 move_time으로 나누어 떨어지지 않는다면, 추가로 한 번 더 이동할 수 있음
        if ticks % move_time > int64(v) {
            moves++
        }

		// 해당 트럭이 운반할 수 있는 총량 계산
		// w[i]는 해당 트럭이 한 번 왕복할 때 운반할 수 있는 최대 무게
		total_cap := int64(w[i]) * moves
        
		// 해당 트럭이 운반할 수 있는 금, 은의 양 계산
		can_carry_gold := min(total_cap, int64(g[i]))
		can_carry_silver := min(total_cap, int64(s[i]))
		// 만약 금과 은을 동시에 운반할 수 있다면, 운반 가능한 양을 조정
		can_carry := min(total_cap, int64(g[i]+s[i]))

		// 금과 은의 양을 합산
		total_carried_gold += can_carry_gold
		total_carried_silver += can_carry_silver
		total_carried += can_carry
	}

	// 합산한 금과 은의 양이 필요한 양을 충족하는지 확인
	// 만약 금과 은의 양이 각각 필요한 양보다 적다면, 운반할 수 없으므로 false 반환
	if total_carried_gold < nG || total_carried_silver < nS {
		return false
	}

	// 만약 총 운반 가능한 양이 필요한 금과 은의 양의 합보다 적다면, 운반할 수 없으므로 false 반환
	if total_carried < nG+nS {
		return false
	}

	return true
}

func solution(needGold, needSilver int, gold, silver, w, t []int) int64 {
	// 0 ≤ needGold, needSilver ≤ 10^9
	// 0 ≤ gold[i], silver[i] ≤ 10^9
	// 1 ≤ w[i] ≤ 10^2
	// 1 ≤ t[i] ≤ 10^5

	left := int64(0)
	right := int64(4e14) // 충분히 큰 값으로 설정

	// 이진 탐색을 통해 최소 시간을 찾음
	// left는 0, right는 최대 시간으로 설정
	for left <= right {
		mid := (left + right) / 2
		// mid 시간 내에 필요한 금과 은을 운반할 수 있는지 확인
		if checkCanDeliver(mid, needGold, needSilver, gold, silver, w, t) {
			right = mid - 1 // 더 적은 시간으로도 가능하므로 왼쪽으로 이동
		} else {
			left = mid + 1 // 더 많은 시간이 필요하므로 오른쪽으로 이동
		}
	}

	// 이진 탐색이 끝나면 left는 최소 시간을 가리키게 됨
	// right는 mid - 1이므로, left는 그 다음 시간
	// 따라서 left - 1이 최소 시간임
	return left - 1
}