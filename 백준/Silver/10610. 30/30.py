import sys
input = sys.stdin.readline

N = list(map(int, list(input().rstrip())))
bucket = [0]*10
check = [0]*3
sum = 0
result = ''
for i in N:
    bucket[i] += 1
    if i != 0:
        check[i%3] += 1
    sum += i
if bucket[0] == 0 or sum%3 != 0:
    print(-1)
else:
    for i in range(10):
        result = str(i)*bucket[i] + result
    print(result)