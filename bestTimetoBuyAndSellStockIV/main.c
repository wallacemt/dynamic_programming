#include <stdlib.h>
#include <string.h>

int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize < 2 || k == 0) return 0;

    if (k >= pricesSize / 2) {
        int maxProfit = 0;
        for (int i = 1; i < pricesSize; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    int* buy = (int*)malloc((k + 1) * sizeof(int));
    int* sell = (int*)malloc((k + 1) * sizeof(int));

    for (int i = 0; i <= k; i++) {
        buy[i] = INT_MIN;
        sell[i] = 0;
    }

    for (int i = 0; i < pricesSize; i++) {
        for (int j = 1; j <= k; j++) {
            buy[j] = fmax(buy[j], sell[j - 1] - prices[i]);
            sell[j] = fmax(sell[j], buy[j] + prices[i]);
        }
    }

    int result = sell[k];
    free(buy);
    free(sell);
    return result;
}
