def solution(n):
    n = str(n)
    answer = []
    answer = list(n)
    answer.reverse()
    answer = [*map(int, answer)]
    return answer