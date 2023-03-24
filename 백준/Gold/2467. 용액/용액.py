import sys
input = sys.stdin.readline

N = int(input())
arr = [*map(int, input().split())]
summ = arr[0] + arr[-1]
st, ed = 0, len(arr)-1
check = arr[0] + arr[-1]
x, y = 0, len(arr)-1
while 1:
    if summ == 0:
        break
    if summ > 0:
        summ -= arr[ed]
        ed -= 1
        if st == ed:
            break
        summ += arr[ed]
        if abs(summ) < abs(check):
            check = summ
            y = ed
            x = st
    else:
        summ -= arr[st]
        st += 1
        if st == ed:
            break
        summ += arr[st]
        if abs(summ) < abs(check):
            check = summ
            x = st
            y = ed

print(arr[x], arr[y])
