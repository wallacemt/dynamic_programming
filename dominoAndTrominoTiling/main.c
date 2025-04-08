#include <stdio.h>
#include <stdlib.h>

int numTilings(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int MOD = 1000000007;
    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
    }
    
    return dp[n];
}


