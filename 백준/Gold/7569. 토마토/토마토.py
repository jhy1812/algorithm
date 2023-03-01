import sys
from collections import deque
input = sys.stdin.readline

def bfs(lst):
    global maxx
    queue = deque()
    queue.extend(lst)
    while queue:
        now = queue.popleft()
        for i in range(6):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            nh = now[2] + dh[i]
            if i < 4:
                if N*now[2] <= ny < N*(now[2]+1) and 0 <= nx < M:
                    if visited[ny][nx] == -1 and stor[ny][nx] == 0:
                        stor[ny][nx] = 1
                        visited[ny][nx] = visited[now[0]][now[1]] + 1
                        queue.append((ny, nx, nh))
                    elif visited[ny][nx] > visited[now[0]][now[1]] + 1 and stor[ny][nx] == 1:
                        visited[ny][nx] = visited[now[0]][now[1]] + 1
                        queue.append((ny,nx,nh))
                    if visited[ny][nx] > maxx:
                        maxx = visited[ny][nx]
            else:
                if 0 <= ny < N*H and 0 <= nx < M:
                    if visited[ny][nx] == -1 and stor[ny][nx] == 0:
                        stor[ny][nx] = 1
                        visited[ny][nx] = visited[now[0]][now[1]] + 1
                        queue.append((ny,nx,nh))
                    elif visited[ny][nx] > visited[now[0]][now[1]] + 1 and stor[ny][nx] == 1:
                        visited[ny][nx] = visited[now[0]][now[1]] + 1
                        queue.append((ny,nx,nh))
                    if visited[ny][nx] > maxx:
                        maxx = visited[ny][nx]


M, N, H = [*map(int, input().split())]
stor = [[0 for _ in range(M)] for _ in range(N*H)]
visited = [[-1 for _ in range(M)] for _ in range(N*H)]
dy = [-1, 1, 0, 0, -N, N]
dx = [0, 0, -1, 1, 0, 0]
dh = [0, 0, 0, 0, -1, 1]
spot = []
maxx = 0
flag = 0
for i in range(N*H):
    stor[i] = [*map(int, input().split())]
for i in range(N*H):
    for j in range(M):
        if stor[i][j] == 1:
            spot.append((i, j, i//N))
            visited[i][j] = 0
bfs(spot)
for i in range(N*H):
    for j in range(M):
        if stor[i][j] == 0:
            flag = 1
            break
    if flag == 1:
        break
if flag == 1:
    print(-1)
else:
    print(maxx)

