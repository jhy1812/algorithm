T = int(input())

for i in range(T):
    lst=list(input().split())
    leng1=len(lst[0])
    leng2=len(lst[1])
    
    new1='a'
    new2='a'
    for j in range(leng2):
        new1+=lst[0]
    for j in range(leng1):
        new2+=lst[1]
    if new1==new2:
        print("#%d yes" %(i+1))
    else:
        print("#%d no" %(i+1))