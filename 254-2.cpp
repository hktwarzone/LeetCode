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
