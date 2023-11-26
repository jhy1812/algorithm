def solution(people, limit):
    people.sort()
    summ = 0
    answer = 0
    
    st = 0
    ed = len(people) - 1
    
    while True:
        if st > ed:
            break
        elif st == ed:
            answer += 1
            break
        elif people[st] + people[ed] <= limit:
            answer += 1
            st += 1
            ed -= 1
        elif people[st] + people[ed] > limit:
            ed -= 1
            answer += 1
            
    return answer