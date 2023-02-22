import sys
input = sys.stdin.readline

N = int(input())
arr = [*map(int, input().split())]
maxx = -21e10
minn = 21e10

for i in arr:
    if maxx < i:
        maxx = i
    if minn > i:
        minn = i
print(minn, maxx)