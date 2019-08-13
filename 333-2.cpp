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
        if (!root) return 0;
        if (isBST(root, INT_MIN, INT_MAX)) return countNode(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
private:
    bool isBST(TreeNode* root, int left, int right) {
        if (!root) return true;
        if (root->val < left || root->val >= right) return false;
        return isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
    }
    int countNode(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
};
