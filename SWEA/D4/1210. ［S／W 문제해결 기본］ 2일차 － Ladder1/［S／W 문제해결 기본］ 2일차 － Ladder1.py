direct_y = [-1, 0, 0]
direct_x = [0, -1, 1]

T = 10
for tc in range(1, T+1):
    test_case = int(input())
    N = 100
    mapp = []
    for _ in range(N):
        mapp += [[*map(int, input().split())]]

    start_spot = 0

    for i in range(N):
        if mapp[N-1][i] == 2:
            start_spot = i
            break
    dy = 99
    dx = start_spot
    while dy != 0:
        flag = 0
        if dx + direct_x[1] >= 0:
            if mapp[dy][dx + direct_x[1]] == 1:
                flag += 1
                dx += direct_x[1]
                while 1:
                    if dx == 0:
                        dy += direct_y[0]
                        break
                    elif mapp[dy][dx + direct_x[1]] == 1:
                        dx += direct_x[1]
                    elif mapp[dy][dx + direct_x[1]] == 0:
                        dy += direct_y[0]
                        break
                        
        if dx + direct_x[2] <= 99:
            if mapp[dy][dx + direct_x[2]] == 1:
                flag += 1
                dx += direct_x[2]
                while 1:
                    if dx == 99:
                        dy += direct_y[0]
                        break
                    elif mapp[dy][dx + direct_x[2]] == 1:
                        dx += direct_x[2]
                    elif mapp[dy][dx + direct_x[2]] == 0:
                        dy += direct_y[0]
                        break

        if flag == 0:
            dy += direct_y[0]

    print(f'#{tc} {dx}')