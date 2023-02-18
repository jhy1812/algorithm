import sys
sys.setrecursionlimit(10**6)

def get_top(bt):
    if bt == 0:
        return 5
    elif bt == 1:
        return 3
    elif bt == 2:
        return 4
    elif bt == 3:
        return 1
    elif bt == 4:
        return 2
    else:
        return 0

def dice_tower(bt, N, sum, level):
    global maxx
    bottom = 0
    top = 0
    one_max = 0
    if level == N:
        if maxx < sum:
            maxx = sum
        return
    for i in range(6):
        if bt == dice[level][i]:
            bottom = i
    top = get_top(bottom)
    for i in range(6):
        if i == top or i == bottom:
            continue
        if one_max < dice[level][i]:
            one_max = dice[level][i]
    sum += one_max
    dice_tower(dice[level][top], N, sum, level+1)



N = int(input())
dice = [0]*N
maxx = 0
for i in range(N):
    dice[i] = [*map(int, input().split())]
for i in range(6):
    dice_tower(dice[0][i], N, 0, 0)

print(maxx)