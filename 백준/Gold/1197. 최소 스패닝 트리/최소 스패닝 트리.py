import sys
sys.setrecursionlimit(10**6)
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

V, E = [*map(int, input().split())]
lst = [0]*E
arr = [-1]*(V+1)
leng = 0
cnt = 0

for i in range(E):
    lst[i] = [*map(int, input().split())]

lst = sorted(lst, key=lambda x:x[2])

for i in lst:
    if findboss(i[0]) != findboss(i[1]):
        cnt += 1
        leng += i[2]
        union(i[0], i[1])
    if cnt == V-1:
        break
print(leng)