int numTrees(int n) {
    if (n <= 1) return 1;

    int* dp = (int*)calloc(n + 1, sizeof(int));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}

