import sys
input = sys.stdin.readline

def union(a, b):
    fa, fb = findboss(a), findboss(b)
    if fa == fb:
        return
    arr[fb] = fa

def findboss(a):
    if arr[a] == -1:
        return a
    ret = findboss(arr[a])
    arr[a] = ret
    return ret

N, M = [*map(int, input().split())]
arr = [-1]*(N+1)
lst = [0]*M
cost = 0
cnt = 0

for i in range(M):
    lst[i] = [*map(int, input().split())]

lst = sorted(lst, key=lambda x:x[2])

for i in lst:
    if findboss(i[0]) != findboss(i[1]):
        cost += i[2]
        cnt += 1
        union(i[0], i[1])
    if cnt == N-2:
        break

print(cost)