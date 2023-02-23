def search(level):
    if level == M:
        print(*path)
        return
    for i in arr:
        if level != 0:
            if path[-1] > i:
                continue
        path.append(i)
        search(level+1)
        path.pop()

N, M = [*map(int, input().split())]
arr = [*map(int, input().split())]
arr.sort()
path = []
search(0)