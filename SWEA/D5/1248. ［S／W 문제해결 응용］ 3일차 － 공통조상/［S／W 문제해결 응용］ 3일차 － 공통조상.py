T=int(input())

for i in range(T):
    V, E, N, M=[*map(int,input().split())]
    dot=[]
    dot.extend(map(int,input().split()))
    A, B=[0,0]
    check1=[]
    check2=[]
    check3=[]
    while M!=1 or N!=1:
        for j in range(1,len(dot),2):
            if dot[j]==N:
                A+=1
                N=dot[j-1]
                check1.append(N)
        for j in range(1,len(dot),2):
            if dot[j]==M:
                M=dot[j-1]
                check2.append(M)
    for j in range(len(check1)):
        for k in range(len(check2)):
            if check1[j]==check2[k]:
                check3.append(check1[j])
    arr=[check3[0]]
    cnt=0
    for j in range(0,len(dot),2):
        arr2=arr
        arr=[]
        for k in range(0,len(arr2)):
            for m in range(0,len(dot),2):    
                if dot[m]==arr2[k]:
                    arr.append(dot[m+1])
                    cnt+=1



    print("#%d %d %d" %(i+1, check3[0], cnt+1))