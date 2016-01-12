/*
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.
Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

*/

struct TreeCountNode {
    long long val;
    int count;
    TreeCountNode *left;
    TreeCountNode *right;
    TreeCountNode(long long x) : val(x), left(NULL), right(NULL) {
        count = 0;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        vector<long long> partial(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            partial[i] = (i > 0) ? partial[i - 1] + nums[i] : nums[i];
        }
        TreeCountNode* root = new TreeCountNode(0);
        int count = 0;
        for (int i = 0; i < partial.size(); i++) {
            count += lteqCount(root, partial[i] - lower) - lteqCount(root, partial[i] - upper - 1);
            insertTree(root, partial[i]);
        }
        return count;
    }
private:
    int lteqCount(TreeCountNode* root, long long value) {
        TreeCountNode* curr = root;
        int res = 0;
        while(curr) {
            if (curr->val <= value) {
                res += curr->count + 1;
                if (curr->val == value) break;
                curr = curr->right;
            }
            else curr = curr->left;
        }
        return res;
    }
    void insertTree(TreeCountNode* root, long long value) {
        TreeCountNode* curr = root;
        while(curr) {
            if (curr->val < value) {
                if (!curr->right) {
                    curr->right = new TreeCountNode(value);
                    return;
                }
                curr = curr->right;
            }
            else {
                curr->count++;
                if (curr->val == value) return;
                if (!curr->left) {
                    curr->left = new TreeCountNode(value);
                    return;
                }
                curr = curr->left;
            }
        }
    }
};
