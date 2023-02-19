import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, year):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = year
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] != year and cheeze[ny][nx] == 0:
                    visited[ny][nx] = year
                    queue.append((ny, nx))
                elif visited[ny][nx] == 0 and cheeze[ny][nx] == 1:
                    visited[ny][nx] = year
                elif cheeze[ny][nx] == 1:
                    visited[ny][nx] += 1
                if visited[ny][nx] > year and cheeze[ny][nx] == 1:
                    visited[ny][nx] = year
                    cheeze[ny][nx] = 0

N, M = [*map(int, input().split())]
cheeze = [0]*N
visited = [[0 for _ in range(M)] for _ in range(N)]
check = [[0 for _ in range(M)] for _ in range(N)]

for i in range(N):
    cheeze[i] = [*map(int, input().split())]
y = 0
while 1:
    if cheeze == check:
        break
    y += 1
    bfs(0, 0, y)
print(y)