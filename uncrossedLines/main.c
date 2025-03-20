int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int** dp = (int**)malloc((nums1Size + 1) * sizeof(int*));
    for (int i = 0; i <= nums1Size; i++) {
        dp[i] = (int*)calloc((nums2Size + 1), sizeof(int));
    }
    
    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    
    int result = dp[nums1Size][nums2Size];
    for (int i = 0; i <= nums1Size; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
