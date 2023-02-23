def search(v, level):
    if level == M:
        print(*path)
        return
    for i in range(v, N+1):
        path.append(i)
        search(i, level+1)
        path.pop()

N, M = [*map(int, input().split())]
path = []
search(1, 0)