T = int(input())

for tc in range(1, T+1):
    N, B = [*map(int, input().split())]

    height = [*map(int, input().split())]
    opti = 200000
    for i in range(1<<N):
        sum = 0
        for j in range(N):
            if i & (1<<j):
                sum += height[j]
        if sum == B:
            opti = sum
            break
        elif sum > B:
            if opti - B > sum - B:
                opti = sum
    print(f'#{tc} {opti-B}')
