def solution(n):
    n = n*2
    answer = 0
    for i in range(1, n//2 + 1):
        if n%i == 0:
            if i%2 == 0 and (n//i)%2 == 0:
                continue
            elif i <= (n//i): 
                answer += 1
    return answer