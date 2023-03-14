import sys
input = sys.stdin.readline

X = int(input())
n = 1
while 1:
    if X > n*(n+1)//2:
        n += 1
        continue
    else:
        break
tmp = X - (n-1)*n//2
if n%2 == 0:
    print(f'{tmp}/{n+1-tmp}')
else:
    print(f'{n+1-tmp}/{tmp}')