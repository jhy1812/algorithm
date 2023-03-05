import copy

T = int(input())

for tc in range(1, T+1):
    N = int(input())
    room = [0]*N
    people_spot = []
    stair = []
    stair1 = []
    stair2 = []
    cnt = 0
    t = []
    minn1 = 21e10
    minn2 = 21e10
    r_minn = 21e10
    for i in range(N):
        room[i] = [*map(int, input().split())]
    for i in range(N):
        for j in range(N):
            if room[i][j] > 1:
                stair.append([i, j])
                t.append(room[i][j])
            if room[i][j] == 1:
                cnt += 1
                people_spot.append([i, j])
    for i in people_spot:
        stair1.append([abs(i[0]-stair[0][0])+abs(i[1]-stair[0][1])+1])
        stair2.append([abs(i[0]-stair[1][0])+abs(i[1]-stair[1][1])+1])
    for k in range(cnt):
        stair1[k].append(stair1[k][0]+t[0])
        stair2[k].append(stair2[k][0]+t[1])
    copy1 = copy.deepcopy(stair1)
    copy2 = copy.deepcopy(stair2)
    for i in range(1<<cnt):
        st1 = []
        st2 = []
        stair1 = copy.deepcopy(copy1)
        stair2 = copy.deepcopy(copy2)
        for j in range(cnt):
            if i & (1<<j):
                st1.append(stair1[j])
            else:
                st2.append(stair2[j])
        st1 = sorted(st1, key=lambda x:x[0])
        st2 = sorted(st2, key=lambda x:x[0])
        if len(st1) > 3:
            for j in range(3, len(st1)):
                if st1[j-3][1] > st1[j][0]:
                    tmp = st1[j-3][1] - st1[j][0]
                    st1[j][0] += tmp
                    st1[j][1] += tmp
        if len(st2) > 3:
            for j in range(3, len(st2)):
                if st2[j-3][1] > st2[j][0]:
                    tmp = st2[j-3][1] - st2[j][0]
                    st2[j][0] += tmp
                    st2[j][1] += tmp
        if len(st1) == 0:
            r_minn = min(r_minn, st2[-1][1])
        elif len(st2) == 0:
            r_minn = min(r_minn, st1[-1][1])
        else:
            minn = max(st1[-1][1], st2[-1][1])
            r_minn = min(r_minn, minn)
    print(f'#{tc} {r_minn}')

