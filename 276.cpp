/*
Paint Fence
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        int dp1 = 0; // last two colors are the same
        int dp2 = k; // last two colors are different
        int sum = k; 
        for (int i = 2; i <= n; i++) {
            dp1 = dp2; // dp1[i] = dp2[i - 1] because color(i - 1) != color(i - 2)
            dp2 = (k - 1) * sum; // dp2[i] = (dp1[i - 1] + dp2[i - 1]) * (k - 1)
            sum = dp1 + dp2;
        }
        return sum;
    }
};
