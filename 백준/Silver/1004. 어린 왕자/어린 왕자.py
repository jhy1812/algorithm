import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    stx, sty, edx, edy = [*map(int, input().split())]
    n = int(input())
    cnt = 0
    for i in range(n):
        cx, cy, r = [*map(int, input().split())]
        if ((stx-cx)**2+(sty-cy)**2-r**2)*((edx-cx)**2+(edy-cy)**2-r**2) < 0:
            cnt += 1

    print(cnt)