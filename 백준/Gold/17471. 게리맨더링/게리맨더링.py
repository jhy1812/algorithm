import sys
from collections import deque
input = sys.stdin.readline

def bfs(v, cnt, team, sum):
    global flag
    visited = [0]*(N+1)
    queue = deque()
    queue.append(v)
    visited[v] = 1
    cnt -= 1
    sum = popul[v-1]
    while queue:
        now = queue.popleft()
        for i in arr[now]:
            if visited[i] == 0 and check[i] == team:
                visited[i] = 1
                queue.append(i)
                cnt -= 1
                sum += popul[i-1]
    if cnt != 0:
        return 0
    else:
        return sum    

N = int(input())
popul = [*map(int, input().split())]
jun = sum(popul)
arr = [0]*(N+1)
check = [0]*(N+1)
minn = 21e10
ccc = 0
for i in range(1, N+1):
    n, *arr[i] = [*map(int, input().split())]
for i in range(1<<N):
    flag = 0
    cnt = 0
    start1 = 0
    for j in range(N):
        if i & (1<<j):
            check[j+1] = 1
            start1 = j + 1
            cnt += 1
        else:
            check[j+1] = 2
            start2 = j + 1
    if  cnt == 0 or cnt == N:
        continue
    else:
        s1 = bfs(start1, cnt, 1, 0)
        s2 = bfs(start2, N-cnt, 2, 0)
        if s1:
            if s2:
                ccc = 1
                minn = min(minn, abs(jun-2*s1))
if ccc == 1:
    print(f'{minn}')
else:
    print(-1)
    