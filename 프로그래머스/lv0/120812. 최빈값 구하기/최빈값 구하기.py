def solution(array):
    maxx = -1
    cnt = 0
    bucket = [0]*1001
    answer = -1
    for i in array:
        bucket[i] += 1
    for i, j in enumerate(bucket):
        if maxx < j:
            cnt = 1
            answer = i
            maxx = j
        elif maxx == j:
            cnt += 1
            answer = -1
    return answer