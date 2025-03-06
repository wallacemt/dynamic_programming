bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool *dp = calloc(len + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                for (int k = 0; k < wordDictSize; k++) {
                    if (strncmp(wordDict[k], s + j, i - j) == 0 && strlen(wordDict[k]) == i - j) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break;
        }
    }
    bool result = dp[len];
    free(dp);
    return result;
}

