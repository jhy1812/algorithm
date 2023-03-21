import sys
input = sys.stdin.readline

def dfs(level, a, b):
    global flag, minn
    if a > b:
        return
    if a == b:
        flag = 1
        minn = min(level, minn)
        return
    for i in range(2):
        if i == 0:
            dfs(level+1, a*2, b)
        else:
            dfs(level+1, a*10+1, b)

A, B = [*map(int, input().split())]
flag = 0
minn = 21e10

dfs(0, A, B)

if flag:
    print(minn+1)
else:
    print(-1)