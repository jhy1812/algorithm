n, m = [*map(int, input().split())]
gob = 1
for i in range(n, n-m, -1):
    gob *= i
for i in range(1, m+1):
    gob = gob//i
print(gob)