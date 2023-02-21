import sys
input = sys.stdin.readline

N = int(input())
col = [0]*1001
area = 0
max_spot = 0
check = 0
for i in range(N):
    spot, height = [*map(int, input().split())]
    col[spot] = height
    if check < height:
        check = height
        max_spot = spot
l_area = 0
r_area = 0
for i in range(1, max_spot):
    if l_area < col[i]:
        l_area = col[i]
    area += l_area
for i in range(1000, max_spot, -1):
    if r_area < col[i]:
        r_area = col[i]
    area += r_area
print(area + check)

