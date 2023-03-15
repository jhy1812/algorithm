import sys
import copy
input = sys.stdin.readline

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

def rot(y, x, s, mapp):
    for i in range(1, s+1):
        start_y = y + dy[3]*i
        start_x = x + dx[2]*i
        tmp = mapp[start_y][start_x]
        dir = 0
        while 1:
            ny = start_y + dy[dir]
            nx = start_x + dx[dir]
            if ny < y - i or ny > y + i or nx < x - i or nx > x + i:
                dir += 1
                ny = start_y + dy[dir]
                nx = start_x + dx[dir]
            if ny == y + dy[3]*i and nx == x + dx[2]*i:
                mapp[start_y][start_x] = tmp
                break
            else:
                mapp[start_y][start_x] = mapp[ny][nx]
            start_y = ny
            start_x = nx
    return mapp

def dfs(level, lst):
    global minn
    if level == K:
        for i in range(N):
            sum = 0
            for j in range(M):
                sum += lst[i][j]
            if minn > sum:
                minn = sum
        return
    temp = copy.deepcopy(lst)
    for i in range(K):
        if used[i] == 0:
            used[i] = 1
            dfs(level+1, rot(order[i][0]-1, order[i][1]-1, order[i][2], lst))
            used[i] = 0
            lst = copy.deepcopy(temp)



N, M, K = [*map(int, input().split())]
arr = [0]*N
order = [0]*K
used = [0]*K
minn = 21e10
for i in range(N):
    arr[i] = [*map(int, input().split())]
for i in range(K):
    order[i] = [*map(int, input().split())]

dfs(0, arr)
print(minn)