import sys
input = sys.stdin.readline

M = int(input())
bucket = [0]*21

for i in range(M):
    order = list(input().split())
    if len(order) == 2:
        num = int(order[1])
    if order[0] == 'add':
        if bucket[num] == 0:
            bucket[num] = 1
    elif order[0] == 'remove':
        if bucket[num] == 1:
            bucket[num] = 0
    elif order[0] == 'check':
        if bucket[num] == 1:
            print(1)
        else:
            print(0)
    elif order[0] == 'toggle':
        if bucket[num] == 1:
            bucket[num] = 0
        else:
            bucket[num] = 1
    elif order[0] == 'all':
        bucket = [0] + [1]*20
    else:
        bucket = [0]*21
