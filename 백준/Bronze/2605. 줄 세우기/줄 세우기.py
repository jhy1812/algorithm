from collections import deque
N = int(input())
num = [*map(int, input().split())]
stack = []
queue = deque()

for i, j  in enumerate(num):
    for k in range(j):
        tmp = stack.pop()
        queue.appendleft(tmp)
        
    stack.append(i+1)
    
    for k in range(j):
        tmp = queue.popleft()
        stack.append(tmp)

print(*stack)