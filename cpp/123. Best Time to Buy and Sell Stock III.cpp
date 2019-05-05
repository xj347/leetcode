class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> firstBuy(n, 0);
        vector<int> secondBuy(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++)
        {
            firstBuy[i] = max(firstBuy[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            secondBuy[i] = max(secondBuy[i+1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, firstBuy[i] + secondBuy[i]);
        }
        return maxProfit;
    }
};