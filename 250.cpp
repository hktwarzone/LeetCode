/*
250. Count Univalue Subtrees 

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        dfs(root, count);
        return count;
    }
private:
    bool dfs(TreeNode* root, int& count) {
        if (!root->left && !root->right) { count++; return true; }
        else if (root->left && !root->right) {
            if (dfs(root->left, count) && root->val == root->left->val) { count++; return true; }
        }
        else if (!root->left && root->right) {
            if (dfs(root->right, count) && root->val == root->right->val) { count++; return true; }
        }
        else {
            bool l = dfs(root->left, count);
            bool r = dfs(root->right, count);
            if (l && r && root->val == root->left->val && root->val == root->right->val) {
                count++; return true;
            }
        }
        return false;
    }
};
