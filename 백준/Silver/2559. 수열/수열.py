import sys
input = sys.stdin.readline

N, K = [*map(int, input().split())]
temp = [*map(int, input().split())]
sum = 0
for i in range(K):
    sum += temp[i]
maxx = sum
for i in range(N-K):
    sum -= temp[i]
    sum += temp[i+K]
    if maxx < sum:
        maxx = sum
print(maxx)

