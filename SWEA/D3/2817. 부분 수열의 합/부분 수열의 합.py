T = int(input())

for tc in range(1, T+1):
    N, K = [*map(int, input().split())]
    numbers = [*map(int, input().split())]
    cnt = 0
    for i in range(1<<N):
        sum = 0
        for j in range(N):
            if i & (1<<j):
                sum += numbers[j]
        if sum == K:
            cnt += 1

    print(f'#{tc} {cnt}')