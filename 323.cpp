/*
323. Number of Connected Components in an Undirected Graph
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function 
to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n <= 1) return n;
        vector<unordered_set<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i].first].insert(edges[i].second);
            adj[edges[i].second].insert(edges[i].first);
        }
        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(adj, visited, i);
            }
        }
        return count;
    }
private:
    void bfs(vector<unordered_set<int>>& adj, vector<bool>& visited, int index) {
        visited[index] = true;
        queue<int> q;
        q.push(index);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it = adj[curr].begin(); it != adj[curr].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }
};
