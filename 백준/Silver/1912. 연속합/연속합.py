import sys
input = sys.stdin.readline

n = int(input())
arr = [*map(int, input().split())]
if max(arr) <= 0:
    print(max(arr))
else:
    maxx = 0
    for i in range(n):
        if arr[i] > 0:
            st = i
            break
    sum = arr[st]
    while 1:
        st += 1
        if st >= n:
            break
        if arr[st] >= 0:
            sum += arr[st]
        elif arr[st] < 0:
            if maxx < sum:
                maxx = sum
            sum += arr[st]
        if sum < 0:
            sum = 0
        if maxx < sum:
            maxx = sum
    print(maxx)