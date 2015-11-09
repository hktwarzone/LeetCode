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
        return factorHelper(n, 2);
    }
private:
    vector<vector<int>> factorHelper(int n, int start) {
        vector<vector<int>> res;
        for (int i = start; i <= n / i; i++) {
            if (n % i == 0) {
                res.push_back({i, n / i});
                vector<vector<int>> children = factorHelper(n / i, i);
                for (int j = 0; j < children.size(); j++) {
                    children[j].insert(children[j].begin(), i);
                    res.push_back(children[j]);
                }
            }
        }
        return res;
    }
};
