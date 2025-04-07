int numDecodings(char* s) {
    int n = strlen(s);
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    if (s[0] != '0') dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i-1] != '0') dp[i] += dp[i-1];
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) dp[i] += dp[i-2];
    }
    return dp[n];
}
