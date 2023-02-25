import sys
input = sys.stdin.readline

N = int(input())
A = [*map(int, input().split())]
B = [*map(int, input().split())]
A = sorted(A, key=lambda x:x)
B = sorted(B, key=lambda x:-x)
sum = 0
for i in range(N):
    sum += A[i]*B[i]
print(sum)