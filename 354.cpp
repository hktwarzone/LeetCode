/*
354. Russian Doll Envelopes
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope 
is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> res;
        for (auto e : envelopes) {
            auto it = lower_bound(res.begin(), res.end(), e[1]);
            if (it == res.end()) {
                res.push_back(e[1]);
            }
            else {
                *it = e[1];
                // In theory we should pop out all elements that larger than e[1], but we just
                // maintain the current max size and only replace the lower bound element
            }
        }
        return (int)res.size();
    }
};
