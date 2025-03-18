int *longestObstacleCourseAtEachPosition(int *obstacles, int obstaclesSize, int *returnSize) {
    if (obstaclesSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *result = malloc(obstaclesSize * sizeof(int));
    int *dp = malloc(obstaclesSize * sizeof(int));
    int len = 0;

    for (int i = 0; i < obstaclesSize; i++) {
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (dp[mid] <= obstacles[i]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        result[i] = lo + 1;
        if (lo == len) {
            dp[len++] = obstacles[i];
        } else {
            dp[lo] = obstacles[i];
        }
    }

    *returnSize = obstaclesSize;
    free(dp);
    return result;
}

