T = int(input())
for tc in range(1, T+1):
    N = int(input())

    arr = [*map(int, input().split())]
    dp = [-1]*N
    dp[0] = 1
    maxx = 1
    for i in range(1, N):
        flag = 0
        check = 0
        for j in range(i-1, -1, -1):
            if arr[i] > arr[j]:
                flag = 1
                check = max(check, dp[j])
                dp[i] = check + 1
                maxx = max(maxx, dp[i])
        if flag == 0:
            dp[i] = 1
    print(f'#{tc} {maxx}')