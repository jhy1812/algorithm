def dice_info(lst, order):
    if order == 1:
        temp = lst[0]
        lst[0] = lst[3]
        lst[3] = lst[5]
        lst[5] = lst[2]
        lst[2] = temp
    elif order == 2:
        temp = lst[0]
        lst[0] = lst[2]
        lst[2] = lst[5]
        lst[5] = lst[3]
        lst[3] = temp
    elif order == 3:
        temp = lst[0]
        lst[0] = lst[4]
        lst[4] = lst[5]
        lst[5] = lst[1]
        lst[1] = temp
    else:
        temp = lst[0]
        lst[0] = lst[1]
        lst[1] = lst[5]
        lst[5] = lst[4]
        lst[4] = temp
    return lst


diract = [[0, 0], [0, 1], [0, -1], [-1, 0], [1, 0]]

N, M, y, x, K = [*map(int, input().split())]
mapp = []
for i in range(N):
    mapp = mapp + [[*map(int, input().split())]]
dice = [0, 0, 0, 0, 0, 0]
dice[5] = mapp[y][x]
order = [*map(int, input().split())]
for i in range(K):
    if x + diract[order[i]][1] > M - 1 or x + diract[order[i]][1] < 0 or y + diract[order[i]][0] > N - 1 or y + diract[order[i]][0] < 0:
        continue
    else:
        y += diract[order[i]][0]
        x += diract[order[i]][1]
        dice = dice_info(dice, order[i])
        if mapp[y][x] == 0:
            mapp[y][x] = dice[5]
        else:
            dice[5] = mapp[y][x]
            mapp[y][x] = 0
        print(dice[0])