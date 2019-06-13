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
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<int> tmp;
        vector<vector<int>> res;
        getFac(n, 2, tmp, res);
        return res;
    }
private:
    void getFac(int n, int start, vector<int>& tmp, vector<vector<int>>& res) {
        for (int i = start; i <= n / i; i++) {
            if (n % i == 0) {
                tmp.push_back(i);
                
                tmp.push_back(n / i);
                res.push_back(tmp);
                tmp.pop_back();
                
                getFac(n / i, i, tmp, res);
                tmp.pop_back();
            }
        }
    }
};
