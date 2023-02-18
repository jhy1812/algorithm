from collections import deque

def bfs(y, x):
    queue = deque()
    visited[y][x] = 1
    queue.append((y, x))
    house = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            y = now[0] + dy[i]
            x = now[1] + dx[i]
            if 0 <= y < N and 0 <= x < N:
                if apt[y][x] == 1:
                    if visited[y][x] == 0:
                        visited[y][x] = 1
                        queue.append((y, x))
                        house += 1
    return house

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
N = int(input())
apt = [0]*N
num = []
cnt = 0
visited = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    apt[i] = list(map(int, list(input())))
for i in range(N):
    for j in range(N):
        if apt[i][j] == 1:
            if visited[i][j] == 0:
                num.append(bfs(i, j))
                cnt += 1
print(cnt)
num.sort()
for i in num:
    print(i)