
int numSquares(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            min = min < dp[i - j * j] ? min : dp[i - j * j];
        }
        dp[i] = min + 1;
    }
    return dp[n];
}