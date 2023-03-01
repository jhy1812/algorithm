import sys
input = sys.stdin.readline

N = int(input())
dp = [[0 for _ in range(10)] for _ in range(N+1)]
if N == 1:
    print(10)
else:
    for i in range(10):
        dp[1][i] = 1
    for i in range(2, N+1):
        for j in range(1, 11):
            for k in range(j):
                dp[i][j-1] += dp[i-1][k]%10007
    sum = 0
    for i in range(10):
        sum += dp[N][i]%10007
    print(sum%10007)
