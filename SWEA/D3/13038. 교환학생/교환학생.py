TC = int(input())

for i in range(TC):
    n = int(input())
    week = [*map(int,input().split())]
    lecture_day = []
    check = []
    for j in range(len(week)):
        days = 0
        cnt = 0
        if week[j] == 1:
            lecture_day = week[j:]+week[:j]
            while True:
                for k in range(len(lecture_day)):
                    days +=1
                    if lecture_day[k] == 1:
                        cnt+=1
                    if cnt == n:
                        break
                if cnt == n:
                    break
        else:
            continue

        check.append(days)
    print('#%d %d'%(i+1,min(check)))

    