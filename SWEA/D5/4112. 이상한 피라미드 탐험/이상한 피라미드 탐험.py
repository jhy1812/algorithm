T = int(input())

for tc in range(1, T+1):
    minji, treasure = [*map(int, input().split())]

    minji_y, treasure_y = minji, treasure
    minji_x, treasure_x = 0, 0
    line = [minji_y, treasure_y]
    
    for i in range(2):
        n = 1
        while 1:
            if n*(n+1)//2 >= line[i]:
                line[i] = n
                break
            n += 1
    minji_x = minji - line[0]*(line[0]-1)//2
    treasure_x = treasure - line[1]*(line[1]-1)//2
    minji_y, treasure_y = line[0], line[1]

    time = 0
    
    if (minji_x - treasure_x)*(minji_y - treasure_y) >= 0:
        if abs(minji_x - treasure_x) > abs(minji_y - treasure_y):
            time = abs(minji_x - treasure_x)
        else:
            time = abs(minji_y - treasure_y)
    else:
        time = abs(minji_x - treasure_x) + abs(minji_y - treasure_y)

    print(f'#{tc} {time}')