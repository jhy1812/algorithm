import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    H, W, N = [*map(int, input().split())]
    if N%H == 0:
        result = str(H)
        if N//H <= 9:
            result += '0' + str(N//H)
        else:
            result += str(N//H)
    else:
        result = str(N%H)
        if N//H+1 <= 9:
            result += '0'+str(N//H+1)
        else:
            result += str(N//H+1)
    print(result)