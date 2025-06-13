from collections import Counter

def solution(array):
    counts = Counter(array)
    
    answer = 0
    max_count = 0
    
    for key, value in counts.items():
        if value == max_count:
            answer = -1
        if value > max_count:
            answer = key
            max_count = value
    
    return answer