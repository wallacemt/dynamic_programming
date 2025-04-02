#include <string.h>

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < strsSize; i++) {
        int zeros = 0, ones = 0;
        for (int k = 0; strs[i][k] != '\0'; k++) {
            if (strs[i][k] == '0') zeros++;
            else ones++;
        }
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                dp[j][k] = dp[j][k] > dp[j - zeros][k - ones] + 1 ? dp[j][k] : dp[j - zeros][k - ones] + 1;
            }
        }
    }
    return dp[m][n];
}

