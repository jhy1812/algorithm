T = int(input())

for tc in range(1, T+1):
    N, M, K, A, B = [*map(int, input().split())]
    jubsu_time = [0] + [*map(int, input().split())]
    jungbi_time = [0] + [*map(int, input().split())]
    people = [0] + [*map(int, input().split())]
    jubsu_chang = [0]*(N+1)
    jubsu_list = []
    jubsu_fin = [[0,0]]
    jungbi_chang = [0]*(M+1)
    now = 1
    summ = 0
    for i, j in enumerate(people):
        if i == 0:continue
        flag = 0
        minn = 21e10
        min_jub = 0
        for k in range(1, N+1):
            if jubsu_chang[k] < minn:
                minn = jubsu_chang[k]
                min_jub = k
            if jubsu_chang[k] <= j:
                jubsu_chang[k] = j + jubsu_time[k]
                jubsu_fin.append([jubsu_chang[k],k,i])
                flag = 1
                if k == A:
                    jubsu_list.append(i)
                break
        if flag == 0:
            jubsu_chang[min_jub] += jubsu_time[min_jub]
            jubsu_fin.append([jubsu_chang[min_jub],min_jub,i])
            if min_jub == A:
                jubsu_list.append(i)

    jubsu_fin = sorted(jubsu_fin, key=lambda x:x[1])
    jubsu_fin = sorted(jubsu_fin, key=lambda x:x[0])
    for i, j in enumerate(jubsu_fin):
        if i == 0:continue
        flag = 0
        minn = 21e10
        min_jung = 0
        for k in range(1, M+1):
            if minn > jungbi_chang[k]:
                minn = jungbi_chang[k]
                min_jung = k
            if jungbi_chang[k] <= j[0]:
                jungbi_chang[k] = j[0] + jungbi_time[k]
                flag = 1
                if k == B:
                    if j[2] in jubsu_list:
                        summ += j[2]
                break
        if flag == 0:
            jungbi_chang[min_jung] += jungbi_time[min_jung]
            if min_jung == B:
                if j[2] in jubsu_list:
                    summ += j[2]
    if summ == 0:
        print(f'#{tc} -1')
    else:
        print(f'#{tc} {summ}')
