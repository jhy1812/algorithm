import sys
from collections import deque
input = sys.stdin.readline

def bfs(v):
    queue = deque()
    queue.append(v)
    visited[v] = 1
    while queue:
        now = queue.popleft()
        for i in arr[now]:
            if visited[i] == 0:
                visited[i] = now
                queue.append(i)
N = int(input())
arr = [[] for _ in range(N+1)]
visited = [0]*(N+1)

for i in range(N-1):
    s, e = [*map(int, input().split())]
    arr[s].append(e)
    arr[e].append(s)
bfs(1)
for i in range(2, N+1):
    print(visited[i])