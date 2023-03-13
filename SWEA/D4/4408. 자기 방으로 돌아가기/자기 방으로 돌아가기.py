T = int(input())

for tc in range(1, T+1):
    N = int(input())
    student_room = []
    for i in range(N):
        student_room += [[*map(int, input().split())]]
    for i in range(N):
        if student_room[i][0]%2 == 1:
            student_room[i][0] = (student_room[i][0]+1)//2
        else:
            student_room[i][0] = student_room[i][0]//2
        if student_room[i][1]%2 == 1:
            student_room[i][1] = (student_room[i][1]+1)//2
        else:
            student_room[i][1] = student_room[i][1]//2
        if student_room[i][1] < student_room[i][0]:
            student_room[i][0], student_room[i][1] =  student_room[i][1], student_room[i][0]

    time = [0]*201
    for i in range(N):
        for j in range(student_room[i][0], student_room[i][1]+1):
            time[j] += 1
    maxx = time[0]
    for i in range(201):
        if maxx < time[i]:
            maxx = time[i]

    print(f'#{tc} {maxx}')
        