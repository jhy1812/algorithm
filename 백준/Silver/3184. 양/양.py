import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque()
    queue.append((y,x))
    visited[y][x] = 1
    sheep = 0
    wolf = 0
    flag = 0
    while queue:
        now = queue.popleft()
        if field[now[0]][now[1]] == 'v':
            wolf += 1
        elif field[now[0]][now[1]] == 'o':
            sheep += 1
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if visited[ny][nx] == 0 and field[ny][nx] != '#':
                    visited[ny][nx] = 1
                    queue.append((ny, nx))
    if wolf >= sheep:
        flag += 1
        return flag, wolf
    else:
        return flag, sheep

R, C = [*map(int, input().split())]
field = [0]*R
w = 0
s = 0
visited = [[0 for _ in range(C)] for _ in range(R)]
for i in range(R):
    field[i] = list(input().rstrip())
for i in range(R):
    for j in range(C):
        if field[i][j] != '#' and visited[i][j] == 0:
            flag, ani = bfs(i, j)
            if flag == 1:
                w += ani
            else:
                s += ani
print(s, w)

