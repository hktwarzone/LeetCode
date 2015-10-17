/*
Factor Combinations
umbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.

input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> part;
        vector<vector<int>> res;
        if (n == 1) return res;
        dfs(res, part, n, 2, false);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& part, int n, int start, bool include) {
        if (n == 1) {
            vector<int> tmp = part;
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp);
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                if (n == i && !include) continue;
                part.push_back(i);
                dfs(res, part, n/i, i, true);
                part.pop_back();
            }
        }
    }
};
