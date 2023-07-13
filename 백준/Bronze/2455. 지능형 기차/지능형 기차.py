train = 0
result = 0

for i in range(4):
    a, b = [*map(int, input().split())]
    train += b
    train -= a
    result = max(result, train)

print(result)