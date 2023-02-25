import sys
input = sys.stdin.readline

N = int(input())

if N == 1:
    print(1)
elif N == 2:
    print(1)
else:
    dp = [[0 for _ in range(2)] for _ in range(N+1)]
    dp[1][1] = 1
    dp[2][0] = 1
    for i in range(3, N+1):
        dp[i][0] = dp[i-1][0] + dp[i-1][1]
        dp[i][1] = dp[i-1][0]
    print(dp[N][0] + dp[N][1])