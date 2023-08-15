kda = [*map(int, input().split('/'))]

if kda[0] + kda[2] < kda[1] or kda[1] == 0:
    print('hasu')
else:
    print('gosu')