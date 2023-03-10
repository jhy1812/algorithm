T = int(input())

for tc in range(1, T+1):
    moonja = input()
    cnt = 0
    for i, j in enumerate(moonja):
        if ord(j)-97 == i:
            cnt += 1
        else:
            break
    print(f'#{tc} {cnt}')