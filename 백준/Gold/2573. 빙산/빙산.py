import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, year):
    queue = deque()
    queue.append((y,x))
    visited[y][x] = year
    while queue:
        now = queue.popleft()
        sea = 0
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if iceberg[ny][nx] > 0 and visited[ny][nx] != year:
                visited[ny][nx] = year
                queue.append((ny, nx))
            elif iceberg[ny][nx] <= 0 and visited[ny][nx] != year:
                sea += 1
        if iceberg[now[0]][now[1]] - sea > 0:
            iceberg[now[0]][now[1]] -= sea
        else:
            iceberg[now[0]][now[1]] = 0

N, M = [*map(int, input().split())]
iceberg = [0]*N
year = 0
for i in range(N):
    iceberg[i] = [*map(int, input().split())]
spot = []
for i in range(N):
    for j in range(M):
        if iceberg[i][j] > 0:
            spot.append((i, j))
y = 1
check = [[0]*M for _ in range(N)]
visited = [[0]*M for _ in range(N)]
while 1:
    cnt = 0
    for i in spot:
        if visited[i[0]][i[1]] != y and iceberg[i[0]][i[1]] > 0:
            bfs(i[0], i[1], y)
            cnt += 1
            if cnt >= 2 or iceberg == check:
                year = y-1
                break
    if cnt >= 2 or iceberg == check:
        break
    y += 1
if cnt < 2:
    print(0)
else:
    print(year)
