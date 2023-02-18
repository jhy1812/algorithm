import sys
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def dfs(y, x, cnt):
    global maxx
    bucket[ord(mapp[y][x])-65] = True
    maxx = max(maxx, cnt)
    if maxx >= 26:
        return
    for i in range(4):
        ny = y +dy[i]
        nx = x +dx[i]
        if 0 <= ny < R and 0 <= nx < C:
            if not bucket[ord(mapp[ny][nx])-65]:
                dfs(ny, nx, cnt + 1)
        if maxx >= 26:
            return
    bucket[ord(mapp[y][x])-65] = False

R, C = [*map(int, input().split())]
mapp = [0]*R
bucket = [False]*26
maxx = 1
lim = 0
for i in range(R):
    mapp[i] = list(input())
bucket = [0]*26
dfs(0, 0, 1)
print(maxx)
