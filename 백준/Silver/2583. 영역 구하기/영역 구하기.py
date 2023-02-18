import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    area = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if mapp[ny][nx] == 0 and visited[ny][nx] == 0:
                    visited[ny][nx] = 1
                    queue.append((ny, nx))
                    area += 1
    return area

N, M, K = [*map(int, input().split())]
mapp = [[0]*M for _ in range(N)]
visited = [[0]*M for _ in range(N)]
cnt = 0
areas = []
for i in range(K):
    x1, y1, x2, y2 = [*map(int, input().split())]
    for j in range(y1, y2):
        for k in range(x1, x2):
            mapp[j][k] = 1
for i in range(N):
    for j in range(M):
        if mapp[i][j] == 0 and visited[i][j] == 0:
            areas.append(bfs(i, j))
            cnt += 1
areas.sort()
print(cnt)
print(*areas)
