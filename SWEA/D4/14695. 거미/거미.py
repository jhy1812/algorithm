def plane(x,y,z):
    vector_1 = [x[0]-y[0], x[1]-y[1], x[2]-y[2]]
    #vector_2 = [x[0]-z[0], x[1]-z[1], x[2]-z[2]]
    vector_2 = [y[0]-z[0], y[1]-z[1], y[2]-z[2]]
    
    c = vector_1[0]*vector_2[1]-vector_1[1]*vector_2[0]
    b = vector_1[0]*vector_2[2]-vector_1[2]*vector_2[0]
    a = vector_1[1]*vector_2[2]-vector_1[2]*vector_2[1]
    
    if a==0 and b==0 and c==0:
        return 1
    else:
        return [a, -b, c]

T = int(input())

for i in range(T):
    N = int(input())
    dot = []
    for j in range(N):
        dot.append([*map(int,input().split())])
    cnt=0
    for j in range(len(dot)-2):
        check = plane(dot[j],dot[j+1],dot[j+2])
        if check==1:
            cnt+=1
            continue
        else:
            break
    if cnt==len(dot)-2:
        print("#%d TAK" %(i+1))
    else:
        cnt = 0
        for j in range(len(dot)-1):
            if check[0]*dot[j][0]+check[1]*dot[j][1]+check[2]*dot[j][2]!=check[0]*dot[j+1][0]+check[1]*dot[j+1][1]+check[2]*dot[j+1][2]:
                print("#%d NIE" %(i+1))
                break
            else:
                cnt+=1
        if cnt==len(dot)-1:
            print("#%d TAK" %(i+1))   
