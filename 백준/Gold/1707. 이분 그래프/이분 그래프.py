import sys
from collections import deque
input = sys.stdin.readline

def bfs(v):
    global flag
    queue = deque()
    queue.append(v)
    visited[v] = 1
    n = 1
    while queue:
        now = queue.popleft()
        for i in arr[now]:
            if visited[i] != 0 and visited[i]%2 == visited[now]%2:
                flag += 1
                return
            if visited[i] == 0:
                visited[i] = visited[now] + 1
                queue.append(i)

T = int(input())
for tc in range(1, T+1):
    V, E = [*map(int, input().split())]
    arr = [[] for _ in range(V+1)]
    visited = [0]*(V+1)
    flag = 0
    for i in range(E):
        s, e = [*map(int, input().split())]
        arr[s].append(e)
        arr[e].append(s)
    for i in range(1, V+1):
        if visited[i] == 0:
            bfs(i)
    if flag == 0:
        print('YES')
    else:
        print('NO')