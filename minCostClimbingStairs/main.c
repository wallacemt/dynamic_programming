int minCostClimbingStairs(int* cost, int costSize) {
    int a = cost[0], b = cost[1], c = 0;

    for (int i = 2; i < costSize; i++) {
        c = cost[i] + (a < b ? a : b);
        a = b;
        b = c;
    }

    return (a < b ? a : b);
}
