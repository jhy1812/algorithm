def check_virus(v):
    visited[v] = True
    for i in network[v]:
        if not visited[i]:
            check_virus(i)


N = int(input())
E = int(input())
network = [[] for _ in range(N+1)]
visited = [False]*(N+1)
for i in range(E):
    s, e = [*map(int, input().split())]
    network[s].append(e)
    network[e].append(s)

check_virus(1)
cnt = 0

for i in visited:
    if i:
        cnt += 1

print(cnt-1)