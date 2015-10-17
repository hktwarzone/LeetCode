/*
Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {
       int res = root->val;
       TreeNode* curr = root;
       double mindiff = fabs((double)root->val - target);
       while(curr != NULL) {
           double diff = (double)curr->val - target;
           double fdiff = fabs(diff);
           if (fdiff < mindiff) {
               mindiff = fdiff;
               res = curr->val;
           }
           if (diff == 0) return res;
           else if (diff > 0) {
               curr = curr->left;
           }
           else {
               curr = curr->right;
           }
       }
       return res;
    }
};
