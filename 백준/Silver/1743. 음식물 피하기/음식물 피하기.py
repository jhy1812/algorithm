import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    global cnt
    queue = deque()
    queue.append((y, x))
    visited[y][x] = 1
    while queue:
        now = queue.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny <= N and 0 <= nx <= M:
                if visited[ny][nx] == 0 and school[ny][nx] == 1:
                    visited[ny][nx] = 1
                    queue.append((ny, nx))
                    cnt += 1


N, M, K = [*map(int, input().split())]
school = [[0 for _ in range(M+1)] for _ in range(N+1)]
visited = [[0 for _ in range(M+1)] for _ in range(N+1)]
st = []
maxx = 0
for i in range(K):
    y, x = [*map(int, input().split())]
    st.append((y,x))
    school[y][x] = 1
for i in st:
    if visited[i[0]][i[1]] == 0:
        cnt = 1
        bfs(i[0], i[1])
        maxx = max(cnt, maxx)
print(maxx)