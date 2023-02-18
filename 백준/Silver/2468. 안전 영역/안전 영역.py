import sys
from collections import deque
input = sys.stdin.readline


dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, h):
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            y = now[0] +dy[i]
            x = now[1] +dx[i]
            if 0 <= y < N and 0 <= x < N:
                if visited[y][x] == 0 and mapp[y][x] > h:
                    visited[y][x] = 1
                    queue.append((y,x))

N = int(input())
mapp = [0]*N
maxx = 1
for i in range(N):
    mapp[i] = [*map(int, input().split())]

for i in range(1, 100):
    cnt = 0
    visited = [[0 for _ in range(N)] for _ in range(N)]
    for j in range(N):
        for k in range(N):
            if visited[j][k] == 0 and mapp[j][k] > i:
                bfs(j, k, i)
                cnt += 1
    if maxx < cnt:
        maxx = cnt
print(maxx)