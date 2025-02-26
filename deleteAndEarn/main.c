int deleteAndEarn(int* nums, int numsSize) {
    int dp[10001] = {0};
    for (int i = 0; i < numsSize; i++) {
        dp[nums[i]] += nums[i];
    }
    int prev1 = 0, prev2 = 0, cur = 0;
    for (int i = 0; i <= 10000; i++) {
        cur = fmax(prev1 + dp[i], prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return cur;
}
