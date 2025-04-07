int mincostTickets(int *days, int daysSize, int *costs, int costsSize) {
    int dp[366] = {0};
    int idx = 0;
    for (int i = 1; i <= 365; i++) {
        if (idx < daysSize && i == days[idx]) {
            dp[i] = fmin(fmin(dp[(int)fmax(0, i - 1)] + costs[0], dp[(int)fmax(0, i - 7)] + costs[1]), dp[(int)fmax(0, i - 30)] + costs[2]);
            idx++;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[365];
}

