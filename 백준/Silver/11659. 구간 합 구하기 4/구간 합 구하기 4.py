N, M = [*map(int, input().split())]
num = [0]+[*map(int, input().split())]
spot = []
for i in range(M):
    spot.append([*map(int, input().split())])
sum = 0
for i, j in enumerate(num):
    sum += j
    num[i] = sum
for i in range(M):
    print(num[spot[i][1]] - num[spot[i][0]-1])