#include <stdio.h>
#include <stdlib.h>

int longestArithSeqLength(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    int longest = 2;
    int **dp = (int **)malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int *)calloc(20001, sizeof(int));
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j] + 10000;
            dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
            longest = longest > dp[i][diff] ? longest : dp[i][diff];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return longest;
}
