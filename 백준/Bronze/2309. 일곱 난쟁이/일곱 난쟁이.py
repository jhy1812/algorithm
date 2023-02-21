import sys
input = sys.stdin.readline

path = []
check = []

def h_sum(v, level, sum):
    global check
    if level == 2:
        if sum == 100 and len(path) == 2:
            check = path[:]
        return
    for i in height:
        if i in path:
            continue
        path.append(i)
        h_sum(i, level+1, sum-i)
        path.pop()
height = []
sum = 0
for i in range(9):
    height.append(int(input()))
    sum += height[i]
for i in range(9):
    h_sum(i, 0, sum)
    if len(check) == 2:
        break
height.sort()
for i in height:
    if i in check:
        continue
    print(i)