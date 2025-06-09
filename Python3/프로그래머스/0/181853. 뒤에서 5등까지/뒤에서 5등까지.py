def solution(num_list):
    n_list = num_list[:]
    answer = []
    
    for i in range(5):
        min_idx = 0
        for j in range(len(n_list)):
            if n_list[min_idx] > n_list[j]:
                min_idx = j
        answer.append(n_list[min_idx])
        del n_list[min_idx]
    
    return answer