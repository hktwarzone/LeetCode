/*
Number of Islands II

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which 
turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of 
islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> parents(m * n, -1);
        vector<int> rank(m * n, 0);
        unordered_set<int> isIsland;
        int count = 0;
        vector<int> res;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        for (int i = 0; i < positions.size(); i++) {
            int cid = positions[i].first * n + positions[i].second;
            if (isIsland(cid) == 0) { // skip duplicated island
                count++;
                isIsland.insert(cid);
                for (int j = 0; j < 4; j++) {
                    int nx = positions[i].first + dx[j];
                    int ny = positions[i].second + dy[j];
                    int nid = nx * n + ny;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && isIsland.count(nid) > 0) {
                        int cp = find(cid, parents); // need to recheck cp -- it may be changed in last loop
                        int np = find(nid, parents);
                        if (np != cp) {
                            count--;
                            if (rank[cp] > rank[np]) {
                                parents[np] = cp;
                            }
                            else {
                                parents[cp] = np;
                                if (rank[cp] == rank[np]) rank[np]++; // tiebreaking
                            }
                        }
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
private:
    int find(int id, vector<int>& parents) {
        if (parents[id] == -1) {
            parents[id] = id;
            return id;
        }
        int p = id;
        while(p != parents[p]) {
            p = parents[p];
        }
        return p;
    }
};
