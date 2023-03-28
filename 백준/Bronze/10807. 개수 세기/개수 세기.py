N = int(input())
arr = [*map(int, input().split())]
v = int(input())
cnt = 0
for i in arr:
    if i == v:
        cnt += 1
        
print(cnt)