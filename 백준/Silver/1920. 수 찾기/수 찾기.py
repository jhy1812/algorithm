import sys
input = sys.stdin.readline

N = int(input())
arr = [*map(int, input().split())]
M = int(input())
lst = [*map(int, input().split())]
arr = sorted(arr, key=lambda x:x)
for i in lst:
    flag = 0
    st = 0
    ed = N-1
    mid = (N-1)//2
    while 1:
        if arr[mid] == i:
            print(1)
            break
        elif arr[mid] > i:
            ed = mid-1
            mid = (ed+st)//2
        else:
            st = mid+1
            mid = (st+ed)//2
        if st > ed:
            print(0)
            break

