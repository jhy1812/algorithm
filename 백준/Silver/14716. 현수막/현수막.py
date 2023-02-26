import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 0, 1, -1, 1, -1, 0, 1]
dx = [-1, -1, -1, 0, 0, 1, 1, 1]

def bfs(y, x):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    while queue:
        now = queue.popleft()
        for i in range(8):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 0 and mapp[ny][nx] == 1:
                    visited[ny][nx] = 1
                    queue.append((ny, nx))

N, M = [*map(int, input().split())]
mapp = [0]*N
visited = [[0 for _ in range(M)] for _ in range(N)]
cnt = 0
for i in range(N):
    mapp[i] = [*map(int, input().split())]

for i in range(N):
    for j in range(M):
        if visited[i][j] == 0 and mapp[i][j] == 1:
            bfs(i, j)
            cnt += 1
print(cnt)