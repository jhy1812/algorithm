import sys
from copy import deepcopy
input = sys.stdin.readline

def union(a, b, arr):
    fa, fb = findboss(a, arr), findboss(b, arr)
    if fa == fb:
        return
    arr[fb] = fa

def findboss(a, arr):
    if arr[a] == -1:
        return a
    ret = findboss(arr[a], arr)
    arr[a] = ret
    return ret

def combination(st, sun):
    for i in range(st, len(cal)):
        sun.append(i)
        calc(sun)
        combination(i+2, sun)
        sun.pop()

def calc(sun):
    global maxx
    visited = [0]*len(cal)
    arr = [-1] * (N // 2 + 1)
    check = deepcopy(num)
    for i in sun:
        if cal[i] == '+':
            tmp = sum(check[findboss(i, arr)], check[findboss(i+1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
        elif cal[i] == '-':
            tmp = dif(check[findboss(i, arr)], check[findboss(i + 1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
        else:
            tmp = mul(check[findboss(i, arr)], check[findboss(i + 1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
    for i in range(len(visited)):
        if visited[i] == 1:continue
        if cal[i] == '+':
            tmp = sum(check[findboss(i, arr)], check[findboss(i + 1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
        elif cal[i] == '-':
            tmp = dif(check[findboss(i, arr)], check[findboss(i + 1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
        else:
            tmp = mul(check[findboss(i, arr)], check[findboss(i + 1, arr)])
            union(i, i + 1, arr)
            check[findboss(i, arr)] = tmp
            visited[i] = 1
    maxx = max(maxx, check[findboss(0, arr)])



def sum(a, b):
    return a+b

def dif(a, b):
    return a-b

def mul(a, b):
    return a*b

N = int(input())
eq = list(input().rstrip())

cal = []
num = []
sun = []
maxx = -21e10
for i in range(N):
    if i%2:
        cal.append(eq[i])
    else:
        num.append(int(eq[i]))
if N == 1:
    print(int(eq[0]))
else:
    combination(0, sun)
    print(maxx)

