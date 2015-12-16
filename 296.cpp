/*
Best Meeting Point
A group of people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 
1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where 
distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> allx;
        vector<int> ally;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    allx.push_back(i);
                    ally.push_back(j);
                }
            }
        }
        sort(allx.begin(), allx.end());
        sort(ally.begin(), ally.end());
        int cx = allx[allx.size()/2];
        int cy = ally[ally.size()/2];
        int res = 0;
        for (int i = 0; i < allx.size(); i++) {
            res += abs(allx[i] - cx);
        }
        for (int i = 0; i < ally.size(); i++) {
            res += abs(ally[i] - cy);
        }
        return res;
    }
};

