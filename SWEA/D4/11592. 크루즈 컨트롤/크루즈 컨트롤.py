T = int(input())

for tc in range(1, T+1):
    D, N = [*map(int, input().split())]
    horse = []
    for i in range(N):
        horse += [[*map(int, input().split())]]

    time = 0

    for i in range(N):
        if time < (D-horse[i][0])/horse[i][1]:
            time = (D-horse[i][0])/horse[i][1]
    
    print('#%d %.7f' %(tc, D/time))