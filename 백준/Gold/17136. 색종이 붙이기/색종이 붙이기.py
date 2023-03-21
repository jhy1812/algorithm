import sys
input = sys.stdin.readline

def attach(y, x, leng):
    global st_y, st_x
    for k in range(y, y + leng):
        for m in range(x, x + leng):
            if attached[k][m] == 1:
                st_y = k
                st_x = m
                return 0
            attached[k][m] = 1
    return 1
def detach(y, x, leng, f):
    global st_y, st_x
    for k in range(y, y+leng):
        for m in range(x, x+leng):
            if k == st_y and m == st_x and f == 1:
                return
            attached[k][m] = 0

def dfs(level, cp):
    global minn
    global cnt
    global flag
    if cp >= minn:
        return
    if level == cnt:
        flag = 1
        minn = min(cp, minn)
        return
    if attached[spot[level][0]][spot[level][1]] == 1:
        dfs(level+1, cp)
        return
    for i in range(paper[spot[level][0]][spot[level][1]], 0, -1):
        if color[i] <= 0:continue
        if i > 1:
            if attach(spot[level][0], spot[level][1], i):
                color[i] -= 1
                dfs(level+1, cp+1)
                detach(spot[level][0], spot[level][1], i, 0)
                color[i] += 1
            else:
                detach(spot[level][0], spot[level][1], i, 1)
            continue
        attached[spot[level][0]][spot[level][1]] = 1
        color[i] -= 1
        dfs(level+1, cp+1)
        attached[spot[level][0]][spot[level][1]] = 0
        color[i] += 1

N = 10
paper = [0]*N
minn = 21e10
check = 0
attached = [[0]*N for _ in range(N)]
cnt = 0
spot = []
color = [5]*6
flag = 0
st_x = 0
st_y = 0
for i in range(N):
    paper[i] = [*map(int, input().split())]

for i in range(N):
    for j in range(N):
        if paper[i][j] == 1:
            cnt += 1
            spot.append((i, j))
            for k in range(2, 6):
                ch = 0
                for m in range(i, i+k):
                    for n in range(j, j+k):
                        if 0 <= m < N and 0 <= n < N:
                            if paper[m][n] != 0:
                                ch += 1
                if ch == k**2:
                    paper[i][j] = k
                else:
                    break

dfs(0, 0)
if flag == 0:
    print(-1)
else:
    print(minn)
