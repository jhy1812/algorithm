import sys
input = sys.stdin.readline

def dfs(v, level):
    global maxx
    global sum
    if level > m:
        return
    if maxx < sum:
        maxx = sum
    for i in arr[v]:
        if visited[i[0]] == 0 and level+i[1] <= m:
            visited[i[0]] = level+i[1]
            sum += t[i[0]]
            dfs(i[0], level+i[1])
        elif visited[i[0]] != 0 and visited[i[0]] > level+i[1]:
            visited[i[0]] = level+i[1]
            dfs(i[0], level+i[1])

n, m, r = [*map(int, input().split())]
t = [*map(int, input().split())]
arr = [[] for _ in range(n)]

maxx = 0
for i in range(r):
    s, e, l = [*map(int, input().split())]
    arr[s-1].append([e-1, l])
    arr[e-1].append([s-1, l])

for i in range(n):
    visited = [0] * n
    sum = t[i]
    visited[i] = 1
    dfs(i, 0)
    if maxx < sum:
        maxx = sum
print(maxx)