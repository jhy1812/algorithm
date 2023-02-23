import sys
input = sys.stdin.readline

n = int(input())
tri = [0]*n
dp = [[0 for j in range(i)] for i in range(1, n+1)]
for i in range(n):
    tri[i] = [*map(int, input().split())]
dp[0] = tri[0]
for i in range(1, n):
    for j in range(i+1):
        if j == 0:
            dp[i][j] = tri[i][j] + dp[i-1][0]
        elif j == i:
            dp[i][j] = tri[i][j] + dp[i-1][-1]
        else:
            dp[i][j] = tri[i][j] + max(dp[i-1][j-1], dp[i-1][j])
print(max(dp[n-1]))