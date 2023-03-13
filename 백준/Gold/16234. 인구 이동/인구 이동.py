import sys
from collections import deque

input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def bfs(y, x, day):
    global flag
    queue = deque()
    queue.append((y, x))
    visited[y][x] = day
    check = deque()
    check.append((y, x))
    popul = ingu[y][x]
    cnt = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < N:
                if L <= abs(ingu[now[0]][now[1]] - ingu[ny][nx]) <= R and visited[ny][nx] != day:
                    visited[ny][nx] = day
                    queue.append((ny, nx))
                    check.append((ny, nx))
                    popul += ingu[ny][nx]
                    cnt += 1
                    flag = 1
    if cnt > 1:
        for i in check:
            ingu[i[0]][i[1]] = popul//cnt


N, L, R = [*map(int, input().split())]

ingu = [[0 for _ in range(N)] for _ in range(N)]
visited = [[0 for _ in range(N)] for _ in range(N)]
day = 1
for i in range(N):
    ingu[i] = [*map(int, input().split())]

while 1:
    flag = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] != day:
                bfs(i, j, day)
    if flag == 1:
        day += 1
    else:
        day -= 1
        break
print(day)