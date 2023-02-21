import sys
input = sys.stdin.readline

dy = [1, 1, -1, -1, ]
M, N = [*map(int, input().split())]

stx, sty = [*map(int, input().split())]
t = int(input())
tx = t%(2*M)
ty = t%(2*N)

if M - stx >= tx:
    stx += tx
else:
    if M >= tx - (M - stx):
        stx = M - (tx - (M - stx))
    else:
        stx = tx - (2*M - stx)
if N - sty >= ty:
    sty += ty
else:
    if N >= ty - (N - sty):
        sty = N - (ty - (N - sty))
    else:
        sty = ty - (2*N - sty)
print(stx, sty)

