def check(level, x):    # level - 행, x - 열
    global cnt
    if level == N-1:
        cnt += 1
        return
    col[x] = 1                  # 세로, 대각선 방향 체크
    cross1[level-x+N-1] = 1
    cross2[level+x] = 1
    for i in range(N):
        if col[i] == 0 and cross1[level-i+N] == 0 and cross2[level+i+1] == 0:   # 세로, 대각선 모두 안겹치면
            check(level+1, i)   # 다음 행으로
    col[x] = 0
    cross1[level-x+N-1] = 0
    cross2[level+x] = 0

N = int(input())
cnt = 0
col = [0] * N                   # 세로 방향 체크할 리스트
cross1 = [0] * (2 * N - 1)      # 대각선(/) 체크할 리스트
cross2 = [0] * (2 * N - 1)      # 대각선(\) 체크할 리스트
for i in range(N):
    check(0, i)
print(cnt)
