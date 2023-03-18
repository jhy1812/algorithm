T = int(input())                         
                                         
for tc in range(1, T+1):                 
    N = int(input())                     
    box = [*map(int, input().split())]   
    nakcha = [0]*N                       
                                         
    for i in range(len(box)):            
        cnt = 0                          
        for j in range(i+1, len(box)):   
            if box[i] > box[j]:          
                cnt += 1                 
        nakcha[i] = cnt                  
    maxx = 0                             
                                         
    for i in nakcha:                     
        if maxx < i:                     
            maxx = i                     
    print(f'#{tc} {maxx}')               