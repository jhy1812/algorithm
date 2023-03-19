import sys
from itertools import permutations
input = sys.stdin.readline

def game(N, lst):
    score = 0
    st = 0
    for i in range(N):
        out = 0
        b1 = 0
        b2 = 0
        b3 = 0
        while 1:
            if out == 3:
                break
            if inning[i][lst[st]] == 0:
                out += 1
            elif inning[i][lst[st]] == 1:
                score += b3
                b1, b2, b3 = 1, b1, b2
            elif inning[i][lst[st]] == 2:
                score += b2 + b3
                b1, b2, b3 = 0, 1, b1
            elif inning[i][lst[st]] == 3:
                score += b1 + b2 + b3
                b1, b2, b3 = 0, 0, 1
            else:
                score += b1 + b2 + b3 + 1
                b1, b2, b3 = 0, 0, 0
            st += 1
            if st == 9:
                st = 0
    return score

N = int(input())
inning = [0]*N
maxx = 0
visited = [0]*9
for i in range(N):
    inning[i] = [*map(int, input().split())]
for arr in permutations(range(1,9), 8):
    arr = list(arr[:3]) + [0] + list(arr[3:])
    maxx = max(game(N, arr), maxx)
print(maxx)