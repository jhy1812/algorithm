N, K = [*map(int, input().split())]

arr = []
check = [0 for i in range(26)]
result = 0

for i in range(N):
    tmp = input()
    tmp = tmp[4:-4]
    arr.append(tmp)

def dfs(lv, st):
    global result
    if lv == K:
        ret = 0
        for i in arr:
            flag = 0
            for j in i:
                if check[ord(j) - ord('a')] == 0:
                    flag = 1
                    break
            if flag == 0:
               ret += 1
        if result < ret:
            result = ret       
        return
    for i in range(st, 26):
        if check[i] == 1:
            continue
        check[i] = 1
        dfs(lv + 1, i + 1)
        check[i] = 0

if K < 5:
    print(0)
else:
    K -= 5
    for i in 'antic':
        check[ord(i) - ord('a')] = 1
    dfs(0, 1)
    print(result)