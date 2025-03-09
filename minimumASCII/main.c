int minimumDeleteSum(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i ? dp[i - 1][0] + s1[i - 1] : 0;
    }

    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j ? dp[0][j - 1] + s2[j - 1] : 0;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = fmin(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    return dp[len1][len2];
}
