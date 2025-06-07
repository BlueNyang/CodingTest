jokaBabb = ["aya", "ye", "woo", "ma"]
def checkCanSpeak(word):
    for j in jokaBabb:
        if len(word) == 0:
            return True
        if word.startswith(j):
            return checkCanSpeak(word[len(j):])
    return False

def solution(babbling):
    answer = 0
    for b in babbling:
        if checkCanSpeak(b):
            answer += 1
    return answer