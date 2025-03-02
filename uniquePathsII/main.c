int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGrid[0][0] == 1) return 0; // Starting point is blocked

    int dp[obstacleGridSize][obstacleGridColSize[0]];
    dp[0][0] = 1;
    
    for (int i = 1; i < obstacleGridSize; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }
    
    for (int j = 1; j < obstacleGridColSize[0]; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }
    
    for (int i = 1; i < obstacleGridSize; i++) {
        for (int j = 1; j < obstacleGridColSize[0]; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    return dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}

