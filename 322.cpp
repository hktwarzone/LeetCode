/*
322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the 
fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination 
of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0) return 0;
        vector<int> f(amount + 1, -1);
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) 
               f[coins[i]] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            if (f[i] == -1) {
                int mincount = INT_MAX;
                for (int j = 0; j < coins.size(); j++) {
                    if (i >= coins[j] && f[i - coins[j]] > 0) {
                        mincount = min(mincount, 1 + f[i - coins[j]]);
                    }
                }
                if (mincount < INT_MAX) f[i] = mincount;
            }
        }
        return f[amount];
    }
};
