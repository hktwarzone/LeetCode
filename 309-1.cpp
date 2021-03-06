/*
309. Best Time to Buy and Sell Stock with Cooldown
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> local(n + 2, 0);
        vector<int> global(n + 2, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            local[i + 2] = max(local[i + 1], global[i - 1]) + diff;
            global[i + 2] = max(local[i + 2], global[i + 1]);
        }
        return global[n + 1];
    }
};
