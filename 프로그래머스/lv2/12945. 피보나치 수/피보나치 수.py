def solution(n):
    mod = 1234567
    dp = [0, 1, 1]
    for i in range(3, n+1):
        dp[i%3] = (dp[(i-1)%3] + dp[(i-2)%3])%mod
    answer = dp[n%3]
    return answer