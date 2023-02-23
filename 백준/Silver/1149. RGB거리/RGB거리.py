import sys
input = sys.stdin.readline

N = int(input())
rgb = [0]*N
minn = 21e10
dp = [[0 for _ in range(3)] for _ in range(N)]
for i in range(N):
    rgb[i] = [*map(int, input().split())]
dp[0] = rgb[0]

for i in range(1, N):
    for j in range(3):
        minn = 21e10
        for k in range(3):
            if j == k:
                continue
            if minn > dp[i-1][k]:
                minn = dp[i-1][k]
        dp[i][j] = rgb[i][j] + minn
print(min(dp[N-1]))