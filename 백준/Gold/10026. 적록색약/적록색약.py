import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            y = now[0] + dy[i]
            x = now[1] + dx[i]
            if 0 <= y < N and 0 <= x < N:
                if picture[y][x] == picture[now[0]][now[1]]:
                    if visited[y][x] == 0:
                        visited[y][x] = 1
                        queue.append((y, x))

N = int(input())
picture = [0]*N
visited = [[0 for _ in range(N)] for _ in range(N)]
cnt = 0
for i in range(N):
    picture[i] = list(input())

for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            bfs(i, j)
            cnt += 1
print(cnt, end=' ')
cnt = 0
visited = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if picture[i][j] == 'G':
            picture[i][j] = 'R'
for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            bfs(i, j)
            cnt += 1
print(cnt)