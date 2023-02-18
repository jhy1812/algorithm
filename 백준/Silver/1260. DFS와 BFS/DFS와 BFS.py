from collections import deque

def dfs(v):
    visited[v] = 1
    print(v, end=' ')
    for i in range(N+1):
        if arr[v][i] == 1:
            if visited[i] == 0:
                dfs(i)

def bfs(v):
    queue = deque()
    queue.append(v)
    visited[v] = 1
    print(v, end=' ')
    while queue:
        now = queue.popleft()
        for i in range(N+1):
            if arr[now][i] == 1:
                if visited[i] == 0:
                    visited[i] = 1
                    print(i, end=' ')
                    queue.append(i)

N, M, V = [*map(int, input().split())]
arr = [[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(M):
    s, e = [*map(int, input().split())]
    arr[s][e] = 1
    arr[e][s] = 1

visited = [0]*(N+1)
dfs(V)
print()
visited = [0]*(N+1)
bfs(V)