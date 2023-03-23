def solution(dot):
    answer = 0
    if dot[1] > 0 and dot[0] > 0:
        answer = 1
    elif dot[1] > 0 and dot[0] < 0:
        answer = 2
    elif dot[1] < 0 and dot[0] < 0:
        answer = 3
    else:
        answer = 4
    return answer