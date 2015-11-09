/*
Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            neighbors[edges[i].first].push_back(edges[i].second);
            neighbors[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited)) return false;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& neighbors, int curr, int parent, vector<bool>& visited) {
        visited[curr] = true;
        for (int i = 0; i < neighbors[curr].size(); i++) {
            if (!visited[neighbors[curr][i]]) {
                if (hasCycle(neighbors, neighbors[curr][i], curr, visited)) return true;
            }
            else if (neighbors[curr][i] != parent) return true;
        }
        return false;
    }
};
