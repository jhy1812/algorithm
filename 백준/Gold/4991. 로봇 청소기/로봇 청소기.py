import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, cnt):
    global flag
    check_num = cnt
    visited = [[-1 for _ in range(M)] for _ in range(N)]
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 0
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == -1 and room[ny][nx] != 'x':
                    visited[ny][nx] = visited[now[0]][now[1]] + 1
                    queue.append((ny, nx))
                    if room[ny][nx] != '.':
                        arr[room[y][x]][room[ny][nx]] = visited[ny][nx]
                        check_num -= 1
        if check_num == 1:
            break
    if check_num > 1:
        flag = 1
        return

def dfs(v, level, cnt, sum):
    global minn
    if sum > minn:
        return
    if level == cnt-1:
        if minn > sum:
            minn = sum
        return
    for i in range(1, cnt):
        if used[i] == 0:
            used[i] = 1
            dfs(i, level+1, cnt, sum+arr[v][i])
            used[i] = 0



while 1:
    M, N = [*map(int, input().split())]
    if M == 0 and N == 0:
        break
    room = [0]*N
    flag = 0
    info = []
    cnt = 1
    minn = 21e10
    for i in range(N):
        room[i] = list(input().rstrip())
    for i in range(N):
        for j in range(M):
            if room[i][j] == 'o':
                info.append([0, i, j])
                room[i][j] = 0
            elif room[i][j] == '*':
                info.append([cnt, i, j])
                room[i][j] = cnt
                cnt += 1
    arr = [[0 for _ in range(cnt)] for _ in range(cnt)]
    info = sorted(info, key=lambda x:x[0])
    for i in info:
        bfs(i[1], i[2], cnt)
        if flag == 1:
            break
    if flag == 1:
        print(-1)
    else:
        used = [0]*cnt
        used[0] = 1
        dfs(0, 0, cnt, 0)
        print(minn)