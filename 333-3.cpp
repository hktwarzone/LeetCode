/*
333. Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree 
with largest number of nodes in it.
Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int curr_min = INT_MIN, curr_max = INT_MAX, res = 0;
        largestBST(root, curr_min, curr_max, res);
        return res;
    }
private:
    void largestBST(TreeNode* root, int& curr_min, int& curr_max, int& res) {
        if (!root) return;
        int l_min = INT_MIN, l_max = INT_MAX, r_min = INT_MIN, r_max = INT_MAX;
        int l_res = 0, r_res = 0;
        largestBST(root->left, l_min, l_max, l_res);
        largestBST(root->right, r_min, r_max, r_res);
        if ((!root->left || l_max < root->val) && (!root->right || root->val < r_min)) {
            res = 1 + l_res + r_res;
            curr_min = (root->left) ? l_min : root->val;
            curr_max = (root->right) ? r_max : root->val;
        }
        else {
            res = max(l_res, r_res);
        }
    }
};
