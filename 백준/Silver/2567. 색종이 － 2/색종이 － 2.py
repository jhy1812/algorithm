import sys
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

N = int(input())
paper = [[0 for _ in range(102)] for _ in range(102)]
cnt = 0
for i in range(N):
    x, y = [*map(int, input().split())]
    for j in range(y, y+10):
        for k in range(x, x+10):
            paper[j][k] = 1
for i in range(102):
    for j in range(102):
        if paper[i][j] == 0:
            for k in range(4):
                ny = i + dy[k]
                nx = j + dx[k]
                if 0 <= ny < 101 and 0 <= nx < 101:
                    if paper[ny][nx] == 1:
                        cnt += 1
print(cnt)