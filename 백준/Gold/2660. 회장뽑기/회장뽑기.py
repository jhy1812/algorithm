import sys
from collections import deque
input = sys.stdin.readline

def bfs(v):
    global maxx
    queue = deque()
    queue.append(v)
    visited[v] = 1
    while queue:
        now = queue.popleft()
        if visited[now]-1 > maxx:
            maxx = visited[now] - 1
        for i in arr[now]:
            if visited[i] == 0:
                visited[i] = visited[now] + 1
                queue.append(i)

N = int(input())
arr = [[] for _ in range(N+1)]
bucket = [0]*(N+1)
minn = 21e10
candi = []
while 1:
    s, e = [*map(int, input().split())]
    if s == -1 and e == -1:
        break
    arr[s].append(e)
    arr[e].append(s)
for i in range(1, N+1):
    maxx = 0
    visited = [0]*(N+1)
    bfs(i)
    bucket[i] = maxx
for i, j in enumerate(bucket):
    if i == 0:
        continue
    else:
        if j < minn:
            minn = j
            candi.clear()
            candi.append(i)
        elif j == minn:
            candi.append(i)
candi.sort()
print(f'{minn} {len(candi)}')
print(*candi)