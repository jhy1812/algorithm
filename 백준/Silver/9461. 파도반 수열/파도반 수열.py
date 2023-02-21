import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    N = int(input())
    if 1 <= N <= 3:
        print(1)
    elif 4 <= N <= 5:
        print(2)
    else:
        dp = [0]*(N+1)
        dp[1] = 1
        dp[2] = 1
        dp[3] = 1
        dp[4] = 2
        dp[5] = 2
        for i in range(6, N+1):
            dp[i] = dp[i-1] + dp[i-5]
        print(dp[N])