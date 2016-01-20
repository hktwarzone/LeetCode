/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. The counts array has the property 
where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

struct TreeCountNode {
    int val;
    int count;
    TreeCountNode *left;
    TreeCountNode *right;
    TreeCountNode(int x) : val(x), left(NULL), right(NULL) {
        count = 0;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        if (nums.size() == 1) return vector<int>(1, 0);
        vector<int> res;
        TreeCountNode* root = new TreeCountNode(nums.back());
        res.push_back(0);
        for (int i = nums.size() - 2; i >= 0; i--) {
            TreeCountNode* curr = root;
            int count = 0;
            while(true) {
                if (nums[i] <= curr->val) {
                    curr->count++;
                    if (!curr->left) {
                        curr->left = new TreeCountNode(nums[i]);
                        break;
                    }
                    curr = curr->left;
                }
                else {
                    count += (curr->count + 1);
                    if (!curr->right) {
                        curr->right = new TreeCountNode(nums[i]);
                        break;
                    }
                    curr = curr->right;
                }
            }
            res.push_back(count);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
