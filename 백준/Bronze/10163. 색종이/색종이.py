import sys
input = sys.stdin.readline

N = int(input())
arr = [[0 for _ in range(1001)] for _ in range(1001)]

for i in range(N):
    x1, y1, m, n = [*map(int, input().split())]
    for j in range(x1, x1+m):
        for k in range(y1, y1+n):
            arr[k][j] = i + 1

for i in range(N):
    cnt = 0
    for j in range(1001):
        for k in range(1001):
            if arr[j][k] == i+1:
                cnt += 1
    print(cnt)