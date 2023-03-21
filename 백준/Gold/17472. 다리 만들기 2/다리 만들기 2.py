import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, num):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    mapp[y][x] = num
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 0 and mapp[ny][nx] == 1:
                    visited[ny][nx] = 1
                    mapp[ny][nx] = num
                    queue.append((ny, nx))

def connect(y, x):
    for i in range(4):
        leng = 1
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if mapp[ny][nx] == 0:
                while 1:
                    ny += dy[i]
                    nx += dx[i]
                    if 0 <= ny < N and 0 <= nx < M:
                        if mapp[ny][nx] > mapp[y][x]:
                            if leng > 1:
                                bridge.append([mapp[y][x], mapp[ny][nx], leng])
                                break
                            break
                        elif mapp[ny][nx] == mapp[y][x]:
                            break
                        elif mapp[ny][nx] == 0:
                            leng += 1
                        else:
                            break
                    else:
                        break

def union(a, b):
    fa, fb = findboss(a), findboss(b)
    if fa == fb:
        return
    arr[fb] = fa

def findboss(a):
    if arr[a] == -1:
        return a
    ret = findboss(arr[a])
    arr[a] = ret
    return ret

N, M = [*map(int, input().split())]
visited = [[0]*M for _ in range(N)]
mapp = [0]*N
island_num = 1      # 각 섬에 번호 붙여줄 변수
bridge = []
cnt = 0
leng_sum = 0
for i in range(N):
    mapp[i] = [*map(int, input().split())]

for i in range(N):
    for j in range(M):
        if mapp[i][j] == 1 and visited[i][j] == 0:
            bfs(i, j, island_num)
            island_num += 1

arr = [-1]*island_num

for i in range(N):
    for j in range(M):
        if mapp[i][j] != 0:
            connect(i, j)

if len(bridge) <= island_num - 3:
    print(-1)
else:
    bridge = sorted(bridge, key=lambda x:x[2])
    for i in bridge:
        if findboss(i[0]) != findboss(i[1]):
            leng_sum += i[2]
            union(i[0], i[1])
            cnt += 1
        if cnt == island_num-2:
            break
    if cnt == island_num-2:
        print(leng_sum)
    else:
        print(-1)