T = int(input()) # 테스트 케이스

for tc in range(1, T+1):
    N, Q = [*map(int, input().split())]
    box = [0]*N
    for i in range(1, Q+1):
        L, R = [*map(int, input().split())]
        for j in range(L-1, R):
            box[j] = i
    print(f'#{tc}', end=' ')
    print(*box)