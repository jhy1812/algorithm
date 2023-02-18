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
            y = now[0] + dy[i]
            x = now[1] + dx[i]
            if 0 <= y < h and 0 <= x < w:
                if mapp[y][x] == 1 and visited[y][x] == 0:
                    visited[y][x] = 1
                    queue.append((y, x))

while 1:
    w, h = [*map(int, input().split())]
    if w == 0 and h == 0:
        break
    mapp = [0]*h
    visited = [[0 for _ in range(w)] for _ in range(h)]
    cnt = 0

    for i in range(h):
        mapp[i] = [*map(int, input().split())]
    for i in range(h):
        for j in range(w):
            if mapp[i][j] == 1 and visited[i][j] == 0:
                bfs(i, j)
                cnt += 1
    print(cnt)