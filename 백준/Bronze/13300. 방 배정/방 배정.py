N, K = [*map(int, input().split())]

girl = [0]*7
boy = [0]*7
room = 0
for i in range(N):
    gen, age = [*map(int, input().split())]
    if gen == 0:
        girl[age] += 1
    else:
        boy[age] += 1

for i in range(1, 7):
    if girl[i] != 0 and girl[i]%K == 0:
        room += girl[i]//K
    elif girl[i] != 0:
        room += girl[i]//K + 1

for i in range(1, 7):
    if boy[i] != 0 and boy[i]%K == 0:
        room += boy[i]//K
    elif boy[i] != 0:
        room += boy[i]//K + 1

print(room)