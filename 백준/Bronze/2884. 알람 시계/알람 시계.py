H, M = [*map(int, input().split())]

if M >= 45:
    print(H, M-45)
else:
    M = M - 45 + 60
    H -= 1
    if H == -1:
        H = 23
    print(H, M)