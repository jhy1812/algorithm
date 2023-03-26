import sys
input = sys.stdin.readline

N, S = [*map(int, input().split())]
arr = [*map(int, input().split())]
summ = arr[0]
if summ >= S:
    print(1)
else:
    minn = 21e10
    flag = 0
    st, ed = 0, 1
    while 1:
        if summ < S:
            summ += arr[ed]
            ed += 1
        if summ >= S:
            if minn > ed - st:
                flag = 1
                minn = ed - st
            summ -= arr[st]
            st += 1
        if ed == len(arr) and summ < S:
            break
        if st == len(arr):
            break
    if flag:
        print(minn)
    else:
        print(0)
