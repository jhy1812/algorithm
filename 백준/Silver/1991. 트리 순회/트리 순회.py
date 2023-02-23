import sys
input = sys.stdin.readline

def preorder(v):
    print(chr(v+65), end='')
    for i in arr[v]:
        if i != '.':
            preorder(i)

def inorder(v):
    cnt = 0
    for i in arr[v]:
        cnt += 1
        if i != '.':
            inorder(i)
        if cnt == 1:
            print(chr(v+65), end='')

def postorder(v):
    for i in arr[v]:
        if i != '.':
            postorder(i)
    print(chr(v+65), end='')

N = int(input())
arr = [[] for _ in range(N)]
for i in range(N):
    a, b, c = input().split()
    if b.isalpha():
        arr[ord(a)-65].append(ord(b) - 65)
    else:
        arr[ord(a)-65].append(b)
    if c.isalpha():
        arr[ord(a)-65].append(ord(c) - 65)
    else:
        arr[ord(a)-65].append(c)

preorder(0)
print()
inorder(0)
print()
postorder(0)
