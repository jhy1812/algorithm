import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(lst):
    global minn
    queue = deque()
    queue.extend(lst)
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 0 and box[ny][nx] == 0:
                    visited[ny][nx] = visited[now[0]][now[1]] + 1
                    box[ny][nx] = 1
                    queue.append([ny, nx])
                    minn = max(minn, visited[ny][nx])


M, N = [*map(int, input().split())]
box = [0]*N
visited = [[0 for _ in range(M)] for _ in range(N)]
spot = []
minn = 0
flag = 0
for i in range(N):
    box[i] = [*map(int, input().split())]
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            spot.append([i, j])
            visited[i][j] = 1
bfs(spot)
for i in range(N):
    for j in range(M):
        if box[i][j] == 0:
            flag += 1
            break
    if flag == 1:
        break
if flag == 1:
    print(-1)
elif minn == 0:
    print(minn)
else:
    print(minn-1)


