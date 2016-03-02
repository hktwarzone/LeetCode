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
        int result, gmin, gmax = 0;
        recurBST(root, result, gmin, gmax);
        return result;
    }
private:
    bool recurBST(TreeNode* root, int& count, int& submin, int& submax) {
        if (!root) {
            count = 0;
            return true;
        }
        int leftcount, leftsubmin, leftsubmax, rightcount, rightsubmin, rightsubmax = 0;
        bool leftValid = recurBST(root->left, leftcount, leftsubmin, leftsubmax);
        bool rightValid = recurBST(root->right, rightcount, rightsubmin, rightsubmax);
        if (leftValid && rightValid) {
            submin = (root->left) ? min(leftsubmin, root->val) : root->val;
            submax = (root->right) ? max(rightsubmax, root->val) : root->val;
            if ((!root->left || leftsubmax < root->val) && (!root->right || root->val < rightsubmin)) {
                count = leftcount + rightcount + 1;
                return true;
            }
        }
        count = max(leftcount, rightcount);
        return false;
    }
};
