N = int(input())
sum = 0
for i in range(N):
    C, K = [*map(int, input().split())]
    sum += C*K
print(sum)