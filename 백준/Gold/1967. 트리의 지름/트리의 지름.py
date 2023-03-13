import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v, level):
    global maxx
    global st
    visited[v] = 1
    if maxx < level:
        maxx = level
        st = v
    for i in arr[v]:
        if visited[i[0]] == 0:
            dfs(i[0], level+i[1])
    visited[v] = 0

n = int(input())
arr = [[] for _ in range(n+1)]
visited = [0]*(n+1)
maxx = 0
st = 0
for i in range(n-1):
    s, e, l = [*map(int, input().split())]
    arr[s].append((e, l))
    arr[e].append((s, l))
dfs(1, 0)
dfs(st, 0)
print(maxx)
