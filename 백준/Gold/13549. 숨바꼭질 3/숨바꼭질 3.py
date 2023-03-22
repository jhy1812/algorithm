import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def bfs(n, k):
    global minn
    queue = deque()
    queue.append(n)
    visited[n] = 0
    while queue:
        now = queue.popleft()
        for i in range(3):
            if i == 0:
                new = now-1
                if 0 <= new <= 200000:
                    if visited[new] == -1:
                        queue.append(new)
                        visited[new] = visited[now] + 1
                    elif visited[new] > visited[now] + 1:
                        queue.append(new)
                        visited[new] = visited[now] +1
            elif i == 1:
                new = now + 1
                if 0 <= new <= 200000:
                    if visited[new] == -1:
                        queue.append(new)
                        visited[new] = visited[now] + 1
                    elif visited[new] > visited[now] + 1:
                        queue.append(new)
                        visited[new] = visited[now] + 1
            else:
                new = 2*now
                if 0 <= new <= 200000:
                    if visited[new] == -1:
                        queue.append(new)
                        visited[new] = visited[now]
                    elif visited[new] > visited[now]:
                        queue.append(new)
                        visited[new] = visited[now]


N, K = [*map(int, input().split())]
visited = [-1]*200001
bfs(N, K)

print(visited[K])

