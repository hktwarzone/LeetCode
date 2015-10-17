/*
Paint House
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<int> costmin(3, 0);
        int tmp0, tmp1, tmp2;
        costmin[0] = costs[0][0];
        costmin[1] = costs[0][1];
        costmin[2] = costs[0][2];
        for (int i = 1; i < costs.size(); i++) {
            tmp0 = min(costmin[1], costmin[2]) + costs[i][0];
            tmp1 = min(costmin[0], costmin[2]) + costs[i][1];
            tmp2 = min(costmin[0], costmin[1]) + costs[i][2];
            costmin[0] = tmp0;
            costmin[1] = tmp1;
            costmin[2] = tmp2;
        }
        return min(min(costmin[0], costmin[1]), costmin[2]);
    }
};
