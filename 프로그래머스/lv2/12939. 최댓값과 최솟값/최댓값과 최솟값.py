def solution(s):
    answer = [*map(int, s.split())]
    answer = str(min(answer)) + " " + str(max(answer))
    return answer