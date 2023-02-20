import sys
input = sys.stdin.readline

N = int(input())
dp = [-1]*(N+1)
if N >= 4:
    dp[1] = 0
    dp[2] = 1
    dp[3] = 1
    for i in range(4, N+1):
        check = []
        if i%3 == 0:
            check.append(dp[i//3])
        if i%2 == 0:
            check.append(dp[i//2])
        check.append(dp[i-1])
        dp[i] = min(check) + 1
    print(dp[N])
elif N == 1:
    print(0)
else:
    print(1)