def solution(m, n, puddles):
    area = [[0 for _ in range(m+1)] for _ in range(n+1)]
    
    for i in puddles:
        area[i[1]][i[0]] = -1
        
    for i in range(1, n+1):
        if area[i][1] == -1:
            break
        area[i][1] = 1
        
    for j in range(1, m+1):
        if area[1][j] == -1:
            break
        area[1][j] = 1
            
    for i in range(2, n+1):
        for j in range(2, m+1):
            if area[i][j] == -1:
                continue
            if area[i-1][j] != -1:
                area[i][j] += area[i-1][j]
            if area[i][j-1] != -1:
                area[i][j] += area[i][j-1]
    
    return area[n][m]%1000000007