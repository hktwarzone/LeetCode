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
