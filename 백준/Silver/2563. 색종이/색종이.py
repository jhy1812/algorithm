N = 100

paper = [[0 for _ in range(N)] for _ in range(N)]
num = int(input())
spot = []
size = 10

for i in range(num):
    spot += [[*map(int, input().split())]]

for i in range(num):
    for j in range(size):
        for k in range(size):
            paper[spot[i][0]+j][spot[i][1]+k] += 1

cnt = 0

for i in range(N):
    for j in range(N):
        if paper[i][j] >= 1:
            cnt += 1
print(cnt)
    