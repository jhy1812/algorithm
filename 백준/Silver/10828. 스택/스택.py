import sys
input = sys.stdin.readline

N = int(input())
stack = []
for i in range(N):
    order = input().split()
    if len(order) > 1:
        num = int(order[1])
    if order[0] == 'push':
        stack.append(num)
    elif order[0] == 'pop':
        if len(stack) == 0:
            print(-1)
        else:
            tmp = stack.pop()
            print(tmp)
    elif order[0] == 'size':
        print(len(stack))
    elif order[0] == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    else:
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])