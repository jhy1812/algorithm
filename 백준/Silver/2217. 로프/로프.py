import sys
input = sys.stdin.readline

N = int(input())
mw = [0]*N
for i in range(N):
    mw[i] = int(input())
mw = sorted(mw, key=lambda x:-x)
maxx = mw[0]
st = 1
while 1:
    if st >= len(mw):
        break
    if maxx < (st+1)*mw[st]:
        maxx = (st+1)*mw[st]
    st += 1
print(maxx)

