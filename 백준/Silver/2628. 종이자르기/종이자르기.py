M, N = [*map(int, input().split())]

num = int(input())
garo = [0]
sero = [0]
garo_dif = []
sero_dif = []
maxx = 0

for i in range(num):
    dir, ind = [*map(int, input().split())]
    if dir == 0:
        garo.append(ind)
    else:
        sero.append(ind)
garo.append(N)
sero.append(M)
garo.sort()
sero.sort()

for i in range(len(garo)-1):
    garo_dif.append(garo[i+1]-garo[i])
for i in range(len(sero)-1):
    sero_dif.append(sero[i+1]-sero[i])
for i in garo_dif:
    for j in sero_dif:
        if maxx < i*j:
            maxx = i*j
print(maxx)