def solution(balls, share):
    answer = 1
    for i in range(share):
        answer *= balls
        balls -= 1
    tmp = share
    for i in range(share):
        answer = answer//tmp
        tmp -= 1
    return answer