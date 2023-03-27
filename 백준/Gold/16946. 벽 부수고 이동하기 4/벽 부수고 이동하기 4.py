import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, num):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = num
    square = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == -1 and mapp[ny][nx] == 0:
                    square += 1
                    queue.append((ny, nx))
                    visited[ny][nx] = num
    return square

N, M = [*map(int, input().split())]
visited = [[-1]*M for _ in range(N)]
mapp = [0]*N
area = []
check_point = []
cnt = 0

for i in range(N):
    mapp[i] = list(map(int, list(input().rstrip())))

for i in range(N):
    for j in range(M):
        if mapp[i][j] == 0 and visited[i][j] == -1:
            area.append(bfs(i, j, cnt))
            cnt += 1
        if mapp[i][j] == 1:
            check_point.append((i, j))

for i in check_point:
    summ = 0
    check = [-1]*4
    for j in range(4):
        ny = i[0] + dy[j]
        nx = i[1] + dx[j]
        if 0 <= ny < N and 0 <= nx < M:
            if mapp[ny][nx] == 0:
                if visited[ny][nx] in check:
                    continue
                check[j] = visited[ny][nx]
                summ += area[visited[ny][nx]]
    mapp[i[0]][i[1]] = (summ + 1)%10

for i in range(N):
    print(*mapp[i], sep='')
