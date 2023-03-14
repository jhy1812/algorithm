import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 2]

def bfs(v):
    queue = deque()
    queue.append(v)
    visited[v] = 0
    while queue:
        now = queue.popleft()
        for i in range(3):
            if i == 2:
                new = now*dy[i]
            else:
                new = now + dy[i]
            if 0 <= new <= 100000:
                if visited[new] == -1:
                    visited[new] = visited[now] + 1
                    queue.append(new)
                    if new == K:
                        return visited[new]
N, K = [*map(int, input().split())]

visited = [-1]*(100001)

if N == K:
    print(0)
else:
    result = bfs(N)
    print(result)