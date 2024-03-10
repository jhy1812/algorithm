n = int(input())

result = 1

for i in range(n, 0, -1):
    result *= i

for i in range(1, n//2 + 1):
    result //= 2
    result //= i

print(result)