N, M = map(int, input().split())

result = 0

for _ in range(N):
    votes = input().strip()
    if votes.count('O') > M // 2:
        result += 1

print(result)