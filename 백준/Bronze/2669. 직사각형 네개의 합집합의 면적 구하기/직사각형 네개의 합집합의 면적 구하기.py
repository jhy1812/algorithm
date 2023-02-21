import sys
input = sys.stdin.readline

N = 4
arr = [[0 for _ in range(101)] for _ in range(101)]
area = 0
for i in range(N):
    x1, y1, x2, y2 = [*map(int, input().split())]
    for j in range(y1, y2):
        for k in range(x1, x2):
            arr[j][k] = 1
for i in range(101):
    for j in range(101):
        if arr[i][j] == 1:
            area += 1
print(area)