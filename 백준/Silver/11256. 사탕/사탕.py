T = int(input())

for _ in range(T):
    J, N = map(int, input().split())
    box = []
    
    for _ in range(N):
        R, C = map(int, input().split())
        box.append(R * C)
        
    box.sort(reverse=True)
    
    candies = 0
    cnt = 0
    
    for i in box:
        candies += i
        cnt += 1
        if candies >= J:
            break
    
    result = cnt
    print(result)