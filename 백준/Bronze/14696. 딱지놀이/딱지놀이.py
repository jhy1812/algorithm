round = int(input())

for i in range(round):
    a_ddakji = [0]*5
    b_ddakji = [0]*5
    a, *a_shape = [*map(int, input().split())]
    b, *b_shape = [*map(int, input().split())]
    flag = 0
    for j in a_shape:
        a_ddakji[j] += 1
    for j in b_shape:
        b_ddakji[j] += 1

    for j in range(4, 0, -1):
        if a_ddakji[j] == b_ddakji[j]:
            continue
        elif a_ddakji[j] > b_ddakji[j]:
            flag += 1
            print('A')
            break
        else:
            flag += 1
            print('B')
            break
    if flag == 0:
        print('D')