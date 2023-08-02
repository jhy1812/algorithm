mod = 1000000007
def solution(n):
    global mod
    result = [[11, 3], [3, 1]]
    mat = [[4, 1], [-1, 0]]
    
    if n%2 == 0:
        n /= 2
        n -= 1
        while n > 0:
            if n%2 == 1:
                result = mat_mul(result, mat)
            n = n//2
            mat = mat_mul(mat, mat)
    
        if result[1][0] < 0:
            answer = result[1][0] + mod
        else:
            answer = result[1][0]
    else:
        answer = 1
    return answer

def mat_mul(a1, a2):
    global mod
    a3 = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            tmp = 0
            for k in range(2):
                tmp += (a1[i][k] * a2[k][j])%mod
                tmp %= mod
            a3[i][j] = tmp
    return a3    