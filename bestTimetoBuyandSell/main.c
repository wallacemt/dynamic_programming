int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < pricesSize; i++) {
        buy1 = fmax(buy1, -prices[i]);
        sell1 = fmax(sell1, buy1 + prices[i]);
        buy2 = fmax(buy2, sell1 - prices[i]);
        sell2 = fmax(sell2, buy2 + prices[i]);
    }
    return sell2;
}