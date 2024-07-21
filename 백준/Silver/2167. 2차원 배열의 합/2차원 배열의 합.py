N, M = [*map(int, input().split())]
arr = [[0]*(M+1)]
get_sum = [[0]*(M+1) for _ in range(N+1)]

for i in range(N):
    a_row = [0] + [*map(int, input().split())]
    arr.append(a_row)

for i in range(1, N+1):
    for j in range(1, M+1):
        get_sum[i][j] = get_sum[i][j-1] + get_sum[i-1][j] - get_sum[i-1][j-1] + arr[i][j]

K = int(input())
for _ in range(K):
    x1, y1, x2, y2 = [*map(int, input().split())]
    result = get_sum[x2][y2] - get_sum[x1-1][y2] - get_sum[x2][y1-1] + get_sum[x1-1][y1-1]
    print(result)