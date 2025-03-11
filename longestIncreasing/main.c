int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int maxLength = 0;
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        maxLength = fmax(maxLength, dp[i]);
    }
    
    free(dp);
    return maxLength;
}
