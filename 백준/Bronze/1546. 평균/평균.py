import sys
input = sys.stdin.readline

N = int(input())
score = [*map(int, input().split())]
maxx = 0
sum = 0
for i in score:
    if maxx < i:
        maxx = i
    sum += i
print(sum/N/maxx*100)