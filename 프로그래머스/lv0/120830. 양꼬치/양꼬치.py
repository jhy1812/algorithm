def solution(n, k):
    answer = 0
    if n//10 >= 1:
        k -= n//10
    if k < 0:
        k = 0
    answer = n*12000 + k*2000
    return answer