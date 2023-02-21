import sys
input = sys.stdin.readline

N = int(input())
switch = [-1] + [*map(int, input().split())]
student = int(input())

for i in range(student):
    gen, num = [*map(int, input().split())]
    if gen == 1:
        j = 2
        tmp = num
        while 1:
            if switch[tmp] == 1:
                switch[tmp] = 0
            else:
                switch[tmp] = 1
            tmp = num*j
            j += 1
            if tmp > N:
                break
    else:
        if switch[num] == 1:
            switch[num] = 0
        else:
            switch[num] = 1
        j = 1
        while 1:
            r = num + j
            l = num - j
            if 1 <= r <= N and 1<= l <= N:
                if switch[r] == switch[l]:
                    if switch[r] == 1:
                        switch[r], switch[l] = 0, 0
                    else:
                        switch[r], switch[l] = 1, 1
                else:
                    break
            else:
                break
            j += 1
for i in range(1, N+1):
    print(switch[i], end=' ')
    if i%20 == 0:
        print()