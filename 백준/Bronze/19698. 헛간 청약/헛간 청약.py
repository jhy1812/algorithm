N, W, H, L = [*map(int, input().split())]

ret = (W//L) * (H//L)

print(min(N, ret))