T = int(input())

for tc in range(1, T+1):
    N, *score = [*map(int, input().split())]
    sum = 0
    bucket = [0]*101
    cnt = 0
    for i in score:
        sum += i
        bucket[i] += 1
    j = 100
    avg = float(sum)/float(N)
    while 1:
        if j > avg:
           cnt += bucket[j]
        else:
            break
        j -= 1
    result = cnt/N*100
    if (result*10000)%10 >=5:
        result += 0.0005
    print('%.3f' %result, end='')
    print('%')