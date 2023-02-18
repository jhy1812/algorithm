import sys
input = sys.stdin.readline

def dfs(v, level):
    global chon
    visited[v] = 1
    if v == ed:
        chon = level
        return
    for i in arr[v]:
        if visited[i] == 0:
            dfs(i, level+1)

n = int(input())
st, ed = [*map(int, input().split())]
m = int(input())
arr = [[] for _ in range(n+1)]
visited = [0]*(n+1)
chon = -1
for i in range(m):
    s, e = [*map(int, input().split())]
    arr[s].append(e)
    arr[e].append(s)
dfs(st, 0)
print(chon)

