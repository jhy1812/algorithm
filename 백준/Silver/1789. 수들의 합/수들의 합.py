import sys
input = sys.stdin.readline

S = int(input())
n = 1
while 1:
    if S - n*(n+1)//2 > n:
        n += 1
    elif S - n*(n+1)//2 <= n:
        break
print(n)