T = int(input())

for tc in range(1, T+1):
    A, B = input().split()
    len_A = len(A)
    len_B = len(B)
    typing = 0
    leng = 0

    while 1:
        cnt = 0
        if len_A - leng < len_B:
            typing += len_A - leng
            break
        if A[leng] == B[0]:
            for j, i in enumerate(B):
                if i == A[leng+j]:
                    cnt += 1
            if cnt == len(B):
                typing += 1
                leng += len_B
            else:
                typing += 1
                leng += 1
        else:
            typing += 1
            leng += 1
        if leng == len_A:
            break
    print(f'#{tc} {typing}')
