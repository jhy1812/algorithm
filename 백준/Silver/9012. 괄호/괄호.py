import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    str1 = input()
    stack = []
    flag = 0
    for i in str1:
        if i == '(':
            stack.append(i)
        elif i == ')':
            if len(stack) == 0:
                print('NO')
                flag += 1
                break
            else:
                stack.pop()
    if flag == 1:
        continue
    else:
        if len(stack) == 0:
            print('YES')
        else:
            print('NO')