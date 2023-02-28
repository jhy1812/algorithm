T = int(input())

for tc in range(1, T+1):
    people = list(map(int, list(input())))
    st = 1
    needs = people[0]
    empl = 0
    while 1:
        if st >= len(people):
            break
        if people[st] == 0:
            st += 1
            continue
        if st > needs:
            cnt = st - needs
            empl += st - needs
            needs += cnt + people[st]
            st +=1
        else:
            needs += people[st]
            st += 1
    print(f'#{tc} {empl}')
