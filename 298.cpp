/*
Binary Tree Longest Consecutive Sequence

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
       if (!root) return 0;
       int res = 0;
       longestHelper(root, res);
       return res;
    }
private:
    int longestHelper(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = longestHelper(root->left, res);
        if (!(root->left && root->left->val == root->val + 1)) l = 0;
        int r = longestHelper(root->right, res);
        if (!(root->right && root->right->val == root->val + 1)) r = 0;
        int local = max(l, r) + 1;
        res = max(res, local);
        return local;
    }
};
