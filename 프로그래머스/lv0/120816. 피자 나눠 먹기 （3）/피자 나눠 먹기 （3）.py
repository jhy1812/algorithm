def solution(slice, n):
    answer = 1
    while 1:
        if (answer*slice)//n >= 1:
            break
        answer += 1
    return answer