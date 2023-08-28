from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(N, M, maps):
    q = deque()
    q.append((0, 0))
    visited = [[1 for i in range(M)] for j in range(N)]
    while q:
        now = q.popleft()
        nowy = now[0]
        nowx = now[1]
        for i in range(4):
            ny = nowy + dy[i]
            nx = nowx + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 1 and maps[ny][nx] == 1:
                    visited[ny][nx] = visited[nowy][nowx] + 1
                    q.append((ny, nx))
                    if ny == N - 1 and nx == M - 1:
                        return visited[ny][nx]
    return -1

def solution(maps):
    
    N = len(maps)
    M = len(maps[0])
    
    return bfs(N, M, maps)