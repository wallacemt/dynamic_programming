#include <limits.h>

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int dp[matrixSize][matrixColSize[0]];

    // Initialize the first row of dp with the first row of the matrix
    for (int j = 0; j < matrixColSize[0]; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Fill the dp table
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            int minPrev = dp[i - 1][j]; // Directly above
            if (j > 0) {
                minPrev = fmin(minPrev, dp[i - 1][j - 1]); // Diagonally left
            }
            if (j < matrixColSize[0] - 1) {
                minPrev = fmin(minPrev, dp[i - 1][j + 1]); // Diagonally right
            }
            dp[i][j] = matrix[i][j] + minPrev;
        }
    }

    // Find the minimum value in the last row
    int minSum = INT_MAX;
    for (int j = 0; j < matrixColSize[0]; j++) {
        minSum = fmin(minSum, dp[matrixSize - 1][j]);
    }

    return minSum;
}

