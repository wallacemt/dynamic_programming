int maxProfit(int* prices, int pricesSize, int fee) {
    int buy = -prices[0], sell = 0;
    for (int i = 1; i < pricesSize; i++) {
        int temp = buy;
        buy = fmax(buy, sell - prices[i]);
        sell = fmax(sell, temp + prices[i] - fee);
    }   
    return sell; 
}
