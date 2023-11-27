#include <string>
#include <vector>
#include <algorithm>

#define MOD 1234567

using namespace std;

long long solution(int n) {
    if (n == 1) {
        return 1;
    }
    
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}