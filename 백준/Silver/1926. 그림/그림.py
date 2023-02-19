import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    global maxx
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    area = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < n and 0 <= nx < m:
                if visited[ny][nx] == 0 and picture[ny][nx] == 1:
                    visited[ny][nx] = 1
                    queue.append((ny, nx))
                    area += 1
    maxx = max(area, maxx)

n, m = [*map(int, input().split())]
picture = [[] for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]
spot = []
cnt = 0
maxx = 0
for i in range(n):
    picture[i] = [*map(int, input().split())]
for i in range(n):
    for j in range(m):
        if picture[i][j] == 1:
            spot.append((i, j))
for i in spot:
    if visited[i[0]][i[1]] == 0:
        bfs(i[0], i[1])
        cnt += 1
print(cnt)
print(maxx)