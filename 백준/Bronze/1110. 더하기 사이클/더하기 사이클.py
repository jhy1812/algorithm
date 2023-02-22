N = int(input())
target = N
if N == 0:
    print(1)
else:
    cnt = 0
    while 1:
        if N < 10:
            sum = N
            N = sum%10 + (N%10)*10
        else:
            sum = N//10 + N%10
            N = sum%10 + (N%10)*10
        cnt += 1
        if N == target:
            break
    print(cnt)
