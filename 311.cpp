/*
Sparse Matrix Multiplication

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || A[0].empty()) return res;
        int n = A.size();
        int m = A[0].size();
        int k = B[0].size();
        unordered_map<int, vector<pair<int, int>>> ht;
        res = vector<vector<int>>(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] != 0) {
                    ht[j].push_back(make_pair(i, A[i][j]));
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                if (B[i][j] != 0 && !ht[i].empty()) {
                    for (auto it = ht[i].begin(); it != ht[i].end(); it++) {
                        res[it->first][j] += it->second * B[i][j];
                    }
                }
            }
        }
        return res;
    }
};
