T = 10

for tc in range(1, T+1):
    N = int(input())
    table = [0]*N
    cnt = 0
    for i in range(N):
        table[i] = [*map(int, input().split())]
    for i in range(N):
        stack = []
        for j in range(N):
            if table[j][i] == 1:
                stack.append(table[j][i])
            elif table[j][i] == 2:
                if len(stack) != 0:
                    cnt += 1
                    stack.clear()
    print(f'#{tc} {cnt}')