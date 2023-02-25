import sys
input = sys.stdin.readline

N = int(input())
score = [0]*(N+1)
for i in range(1, N+1):
    score[i] = int(input())
if N == 1:
    print(score[1])
elif N == 2:
    print(score[1]+score[2])
else:
    dp = [[0 for _ in range(N+1)] for _ in range(2)]
    dp[0][1] = score[1]
    dp[0][2] = score[1]+score[2]
    dp[1][2] = score[2]
    for i in range(3, N+1):
        dp[0][i] = dp[1][i-1] + score[i]
        dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + score[i]
    print(max(dp[0][N], dp[1][N]))