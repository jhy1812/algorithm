def check_bingo(arr):
    cnt = 0

    for i in range(N):
        if arr[i] == [0]*5:
            cnt += 1

    for i in range(N):
        flag = 0
        for j in range(N):
            if arr[j][i] != 0:
                flag += 1
                break
        if flag == 0:
            cnt += 1

    flag = 0
    for i in range(N):
        if arr[i][i] != 0:
            flag += 1
            break
    for i in range(N):
        if arr[i][N-i-1] != 0:
            flag += 1
            break
    cnt += 2-flag

    return cnt

N = 5
bingo = [0]*N
order = []

for i in range(N):
    bingo[i] = [*map(int, input().split())]

for i in range(N):
    order.extend([*map(int, input().split())])

count = 0
indexx = 0

for i in range(N**2):
    for j in range(N):
        for k in range(N):
            if order[i] == bingo[j][k]:
                bingo[j][k] = 0
            if i >= 11:
                count = check_bingo(bingo)
                if count >= 3:
                    indexx = i
                    break
        if count >= 3:
            break
    if count >= 3:
        break

print(indexx+1)