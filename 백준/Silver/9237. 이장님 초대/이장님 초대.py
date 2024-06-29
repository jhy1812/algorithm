n = int(input())
tree = list(map(int, input().split()))

tree.sort(reverse = True)

result = 0

for i in range(n):
    tmp = i + 2 + tree[i]
    if tmp > result:
        result = tmp;

print(result)
