# import sys
# input = sys.stdin.readline

w = [0]
v = [0]
dp = [0]*100001

n , k = [*map(int ,input().split())]

for i in range(n):
    ww, vv = [*map(int, input().split())]
    w.append(ww)
    v.append(vv)

for i in range(1, n+1):
    for j in range(k, 0, -1):
        if w[i] <= j:
            dp[j] = max(dp[j], dp[j-w[i]]+v[i])
print(dp[k])