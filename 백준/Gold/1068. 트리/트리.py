import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v):
    global ed
    global cnt
    if v == ed:
        return
    count = 0
    for i in arr[v]:
        if i == ed:
            continue
        dfs(i)
        count += 1
    if count == 0:
        cnt += 1

N = int(input())
arr = [[] for _ in range(N)]
lst = [*map(int, input().split())]
cnt = 0
st = 0
for i, j in enumerate(lst):
    if j != -1:
        arr[j].append(i)
    else:
        st = i
ed = int(input())
dfs(st)
print(cnt)


