import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v, level):
    global maxx
    global st
    if maxx < level:
        maxx = level
        st = v
    visited[v] = 1
    for i in arr[v]:
        if visited[i[0]] == 0:
            dfs(i[0], level+i[1])
    visited[v] = 0
V = int(input())
arr = [[] for _ in range(V+1)]
visited = [0]*(V+1)
maxx = 0
st = 0
for i in range(V):
    s, *lst = [*map(int, input().split())]
    for i in range(0, len(lst)-1, 2):
        arr[s].append((lst[i], lst[i+1]))
dfs(1, 0)
dfs(st, 0)
print(maxx)