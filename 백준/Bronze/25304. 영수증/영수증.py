X = int(input())
N = int(input())
sum = 0
for i in range(N):
    x, y = [*map(int, input().split())]
    sum += x*y
if X == sum:
    print('Yes')
else:
    print('No')