/*
Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        int n = rooms.size();
        int m = rooms[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, n, m, i, j);
                }
            }
        }
    }
private:
    void bfs(vector<vector<int>>& rooms, int& n, int& m, int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int cx = node.first + dx[i];
                int cy = node.second + dy[i];
                if (cx >= 0 && cx < n && cy >= 0 && cy < m && rooms[cx][cy] != -1 && rooms[cx][cy] > rooms[node.first][node.second] + 1) {
                    rooms[cx][cy] = rooms[node.first][node.second] + 1;
                    q.push(make_pair(cx, cy));
                }
            }
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
};
