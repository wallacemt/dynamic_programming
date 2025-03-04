int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int maxSide = 0;
    int dp[matrixSize][*matrixColSize];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxSide = fmax(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}
