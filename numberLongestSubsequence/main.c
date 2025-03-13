int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* count = (int*)malloc(numsSize * sizeof(int));
    int maxLength = 0, result = 0;
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        count[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                }
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            result = count[i];
        } else if (dp[i] == maxLength) {
            result += count[i];
        }
    }
    free(dp);
    free(count);
    return result;
}
