def solution(A,B):
    answer = 0

    A.sort()
    B.sort()
    
    l = len(A)
    
    for i in range(l):
        answer += A[i]*B[l-i-1]
    
    return answer