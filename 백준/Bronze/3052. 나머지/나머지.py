import sys
input = sys.stdin.readline

bucket = [0]*42
cnt = 0
for i in range(10):
    num = int(input())
    bucket[num%42] += 1
for i in bucket:
    if i != 0:
        cnt += 1
print(cnt)