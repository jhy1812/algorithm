def solution(n):
    answer = 1
    while 1:
        if (answer*6)%n == 0:
            break
        answer += 1
    return answer