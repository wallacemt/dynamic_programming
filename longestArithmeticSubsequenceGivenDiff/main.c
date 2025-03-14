#include <stdlib.h>
#include <string.h>

int longestSubsequence(int* arr, int arrSize, int difference) {
    if (arrSize == 0) return 0;

    int maxLength = 0;
    int *dp = (int*)calloc(20001, sizeof(int)); // To handle values from -10000 to 10000

    for (int i = 0; i < arrSize; i++) {
        int adjustedValue = arr[i] + 10000; // Adjust to non-negative index
        if (adjustedValue - difference >= 0 && adjustedValue - difference <= 20000) {
            dp[adjustedValue] = dp[adjustedValue - difference] + 1;
        } else {
            dp[adjustedValue] = 1;
        }
        maxLength = fmax(maxLength, dp[adjustedValue]);
    }

    free(dp);
    return maxLength;
}

