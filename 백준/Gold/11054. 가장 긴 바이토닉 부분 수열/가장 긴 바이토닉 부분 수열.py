import sys
input = sys.stdin.readline

N = int(input())

arr = [*map(int, input().split())]
dp = [[0 for _ in range(N)] for _ in range(2)]
check = [0]*N
dp[0][0] = 1
for i in range(1, N):
    flag = 0
    for j in range(i-1, -1, -1):
        if arr[i] > arr[j]:
            if dp[0][i] < dp[0][j] + 1:
                dp[0][i] = dp[0][j] + 1
                flag = 1
    if flag == 0:
        dp[0][i] = 1

for i in range(N-1, -1, -1):
    flag = 0
    for j in range(i+1, N):
        if arr[i] > arr[j]:
            if dp[1][i] < dp[1][j] + 1:
                dp[1][i] = dp[1][j] + 1
                flag = 1
    if flag == 0:
        dp[1][i] = 1

for i in range(N):
    check[i] = dp[0][i] + dp[1][i] - 1

print(max(check))