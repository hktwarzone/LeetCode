/*
188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k < 1 || prices.size() < 2) return 0;
        if (k >= prices.size() / 2) return maxProfit2(prices);
        int res = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < prices.size(); j++) {
                dp[j][i] = dp[j - 1][i];
                for (int m = 0; m < j; m++) {
                    dp[j][i] = max(dp[j][i], dp[m][i - 1] + prices[j] - prices[m]);
                }
            }
            res = max(res, dp[prices.size() - 1][i]);
        }
        return res;
    }
private:
    int maxProfit2(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
