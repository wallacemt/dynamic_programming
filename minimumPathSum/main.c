int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int dp[gridSize][gridColSize[0]];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < gridColSize[0]; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            dp[i][j] = grid[i][j] + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }
    
    return dp[gridSize - 1][gridColSize[0] - 1];
}
