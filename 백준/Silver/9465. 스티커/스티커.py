import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    n = int(input())
    sti = [0]*2
    for i in range(2):
        sti[i] = [*map(int, input().split())]
    if n == 1:
        print(max(sti[0][0], sti[1][0]))
    elif n == 2:
        score1 = sti[0][0] + sti[1][1]
        score2 = sti[1][0] + sti[0][1]
        print(max(score1, score2))
    else:
        dp = [[0]*n for _ in range(2)]
        dp[0][0] = sti[0][0]
        dp[1][0] = sti[1][0]
        dp[0][1] = sti[0][1] + sti[1][0]
        dp[1][1] = sti[1][1] + sti[0][0]
        for i in range(2, n):
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sti[0][i]
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sti[1][i]
        print(max(dp[0][n-1], dp[1][n-1]))