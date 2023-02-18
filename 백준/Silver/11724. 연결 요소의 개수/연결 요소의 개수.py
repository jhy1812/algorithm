from collections import deque
import sys
input = sys.stdin.readline

def bfs(v):
    queue = deque()
    queue.append(v)
    visited[v] = 1
    while queue:
        now = queue.popleft()
        for i in range(N+1):
            if arr[now][i] == 1:
                if visited[i] == 0:
                    visited[i] = 1
                    queue.append(i)

N, M = [*map(int, input().split())]
arr = [[0 for _ in range(N+1)] for _ in range(N+1)]
visited = [0]*(N+1)
cnt = 0
for i in range(M):
    s, e = [*map(int, input().split())]
    arr[s][e] = 1
    arr[e][s] = 1

for i in range(1, N+1):
    if visited[i] == 0:
        bfs(i)
        cnt += 1
print(cnt)