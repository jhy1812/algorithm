import sys
input = sys.stdin.readline

K = int(input())
dir = []
leng = []
for i in range(6):
    d, l = [*map(int ,input().split())]
    dir.append(d)
    leng.append(l)
garo = 0
sero = 0
for i in range(6):
    if dir[i] <= 2:
        if garo < leng[i]:
            garo = leng[i]
    else:
        if sero < leng[i]:
            sero = leng[i]

dir = [dir[-1]] + dir
dir.append(dir[1])
leng = [leng[-1]] + leng
leng.append(leng[1])
indexx = []

for i in range(1, 7):
    if dir[i-1] == dir[i+1]:
        indexx.append(i)
area = garo*sero - leng[indexx[0]]*leng[indexx[1]]
print(area*K)