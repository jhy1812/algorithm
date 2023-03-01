import sys
input = sys.stdin.readline

word = list(input().rstrip())
bucket = [0]*26
spot = []
maxx = 0
for i in word:
    i = i.upper()
    bucket[ord(i)-65] += 1
for i, j in enumerate(bucket):
    if maxx < j:
        maxx = j
        spot.clear()
        spot.append(i)
    elif maxx == j:
        spot.append(i)
if len(spot) > 1:
    print('?')
else:
    print(chr(spot[0]+65))