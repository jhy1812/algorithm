import sys
from collections import deque
input = sys.stdin.readline

def bfs(y, x, check):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    if check == '-':
        dy = [0, 0]
        dx = [-1, 1]
    elif check == '|':
        dy = [-1, 1]
        dx = [0, 0]
    while queue:
        now = queue.popleft()
        for i in range(2):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 0 and room[ny][nx] == check:
                    visited[ny][nx] = 1
                    queue.append((ny, nx))
N, M = [*map(int, input().split())]
room = [0]*N
cnt = 0
visited = [[0 for _ in range(M)] for _ in range(N)]
for i in range(N):
    room[i] = list(input().rstrip())
for i in range(N):
    for j in range(M):
        if visited[i][j] == 0:
            bfs(i, j, room[i][j])
            cnt += 1
print(cnt)