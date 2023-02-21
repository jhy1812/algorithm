N = int(input())

maxx = 0
max_lst = []
for i in range(N, 0, -1):
    stack = [N, i]
    j = 0
    while 1:
        if stack[j] - stack[j+1] >= 0:
            stack.append(stack[j]-stack[j+1])
        else:
            if maxx < len(stack):
                maxx = len(stack)
                max_lst = stack
            break
        j += 1
print(maxx)
print(*max_lst)