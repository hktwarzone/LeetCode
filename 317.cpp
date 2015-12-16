/*
Shortest Distance from All Buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> count(n, vector<int>(m, 0));
        int buildings = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    buildings++;
                    bfs(grid, i, j, dist, count);
                }
            }
        }
        int result = -1;
        int curr_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (count[i][j] == buildings && dist[i][j] < curr_min) {
                    curr_min = dist[i][j];
                    result = curr_min;
                }
            }
        }
        return result;
    }
private:
    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dist, vector<vector<int>>& count) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        queue<pair<int, int>> q, next;
        unordered_set<int> visited;
        int step = 0;
        q.push(make_pair(x, y));
        visited.insert(m * x + y);
        while(!q.empty()) {
            step++;
            while(!q.empty()) {
                pair<int, int> node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && visited.count(m * nx + ny) == 0) {
                        count[nx][ny]++;
                        dist[nx][ny] += step;
                        next.push(make_pair(nx, ny));
                        visited.insert(m * nx + ny);
                    }
                }
            }
            swap(q, next);
        }
    }
};
