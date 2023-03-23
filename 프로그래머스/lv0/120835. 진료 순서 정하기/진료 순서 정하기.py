def solution(emergency):
    bucket = sorted(emergency, key=lambda x:-x)
    visited = [0]*len(emergency)
    for i, j in enumerate(bucket):
        for k, m in enumerate(emergency):
            if j == m and visited[k] == 0:
                visited[k] = 1
                emergency[k] = i + 1
    return emergency