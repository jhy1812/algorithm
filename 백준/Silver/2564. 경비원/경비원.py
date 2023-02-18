def dis_check(dir1, dis1, dir2, dis2, y, x):
    global dis_sum
    flag = 0
    if dir1 == 1:
        if dir2 == 2:
            flag += 1
    elif dir1 == 2:
        if dir2 == 1:
            flag += 1
    elif dir1 == 3:
        if dir2 == 4:
            flag += 2
    elif dir1 == 4:
        if dir2 == 3:
            flag += 2

    if flag == 1:
        dis = N + dis1 + dis2
        if N+M > dis:
            dis_sum += dis
        else:
            dis_sum += 2*(N+M) - dis
    elif flag == 2:
        dis = M + dis1 + dis2
        if N+M > dis:
            dis_sum += dis
        else:
            dis_sum += 2*(N+M) - dis
    else:
        sy, sx = change(dir2, dis2)
        dis_sum += abs(sy-y) + abs(sx-x)

def change(dir, dis):
    if dir == 1:
        y = 0
        x = dis
    elif dir == 2:
        y = N
        x = dis
    elif dir == 3:
        y = dis
        x = 0
    else:
        y = dis
        x = M
    return y, x

M, N = [*map(int, input().split())]     # M - 가로, N - 세로

num = int(input())
store = [0]*num
for i in range(num):
    store[i] = [*map(int, input().split())]     # 1 2 3 4 북 남 서 동
dong = [*map(int, input().split())]
y, x = change(dong[0], dong[1])
dis_sum = 0

for i in range(num):
    dis_check(dong[0], dong[1], store[i][0], store[i][1], y, x)
print(dis_sum)
