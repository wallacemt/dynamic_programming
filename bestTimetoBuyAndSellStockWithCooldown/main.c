int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    
    int buy[pricesSize], sell[pricesSize], cool[pricesSize];
    buy[0] = -prices[0];
    sell[0] = 0;
    cool[0] = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        buy[i] = fmax(buy[i - 1], cool[i - 1] - prices[i]);
        sell[i] = fmax(sell[i - 1], buy[i - 1] + prices[i]);
        cool[i] = fmax(cool[i - 1], sell[i - 1]);
    }
    
    return sell[pricesSize - 1];
}
