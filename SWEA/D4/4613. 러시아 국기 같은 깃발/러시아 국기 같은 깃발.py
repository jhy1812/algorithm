def con(st, level, sum):
    global minn
    if minn < sum:
        return
    if level == N-2:
        if st != 0:
            if minn > sum:
                minn = sum
        return
    for i in range(st, 3):
        if st == 0 and i == 2:
            continue
        con(i, level+1, sum+(M-line[level][i]))

T = int(input())

for tc in range(1, T+1):
    N, M = [*map(int, input().split())]
    flag = [0]*N
    line = [[0 for _ in range(3)] for _ in range(N-2)]  # 두번째 줄부터 N-1번째 줄까지의 색깔 정보 입력할 리스트
    paint = 0
    minn = 21e10
    for i in range(N):
        flag[i] = list(input())         # 현재 깃발 정보
    for i in range(1, N-1):
        for j in range(M):              # 현재 깃발 정보 저장
            if flag[i][j] == 'W':
                line[i-1][0] += 1
            elif flag[i][j] == 'B':
                line[i-1][1] +=1
            else:
                line[i-1][2] += 1

    for i in range(M):                  # 첫번째 줄과 끝줄은 각각 흰색과 빨간색으로 칠함
        if flag[0][i] != 'W':
            paint += 1
        if flag[N-1][i] != 'R':
            paint += 1
    con(0, 0, 0)
    print(f'#{tc} {minn+paint}')