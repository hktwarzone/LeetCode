/*
Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check 
whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.

n - 1 edges + connected
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0 || (n == 1 && edges.empty())) return true;
        if (edges.size() != n - 1) return false;
        vector<vector<int>> neighbor(n);
        for (int i = 0; i < edges.size(); i++) {
            neighbor[edges[i].first].push_back(edges[i].second);
            neighbor[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it = neighbor[node].begin(); it != neighbor[node].end(); it++) {
                if (!visited[*it]) {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
