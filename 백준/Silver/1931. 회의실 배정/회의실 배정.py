import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
t = []
for i in range(N):
    s, e = [*map(int, input().split())]
    t.append([s, e])
t = sorted(t, key=lambda x:x[0])
sche = deque()
sche.append(t[0])
j = 1
while 1:
    if j == N:
        break
    elif sche[-1][0] == t[j][0]:
        if t[j][0] == t[j][1]:
            sche.appendleft(t[j])
        elif sche[-1][0] == sche[-1][1]:
            sche.append(t[j])
        elif sche[-1][1] > t[j][1]:
            sche.pop()
            sche.append(t[j])
    else:
        if sche[-1][1] > t[j][1]:
            sche.pop()
            sche.append(t[j])
        elif sche[-1][1] <= t[j][0]:
            sche.append(t[j])
    j += 1
print(len(sche))
