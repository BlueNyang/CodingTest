def solution(array, height):
    answer = 0
    
    for a in array:
        answer += 1 if a > height else 0
    
    return answer