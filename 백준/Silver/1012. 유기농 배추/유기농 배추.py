from collections import deque

def bfs(y, x):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            y = now[0] + dy[i]
            x = now[1] + dx[i]
            if 0 <= y < N and 0 <= x < M:
                if cabbage[y][x] == 1:
                    if visited[y][x] == 0:
                        visited[y][x] = 1
                        queue.append((y, x))

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

T = int(input())

for tc in range(1, T+1):
    M, N, K = [*map(int, input().split())]
    cabbage = [[0 for _ in range(M)] for _ in range(N)]
    visited = [[0 for _ in range(M)] for _ in range(N)]
    cnt = 0
    for i in range(K):
        x, y = [*map(int, input().split())]
        cabbage[y][x] = 1
    for i in range(N):
        for j in range(M):
            if cabbage[i][j] == 1:
                if visited[i][j] == 0:
                    bfs(i, j)
                    cnt += 1

    print(cnt)