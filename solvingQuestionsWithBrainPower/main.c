long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long dp[questionsSize + 1]; 
    dp[questionsSize] = 0; 

    for (int i = questionsSize - 1; i >= 0; i--) {
        int points = questions[i][0];
        int brainpower = questions[i][1];
        long long solve = points + (i + brainpower + 1 < questionsSize ? dp[i + brainpower + 1] : 0);
        long long skip = dp[i + 1];
        dp[i] = fmax(solve, skip);
    }

    return dp[0];
}
