/*
Closest Binary Search Tree Value II
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> precStack;
        stack<int> succStack;
        getPredecessor(root, target, precStack);
        getSuccessor(root, target, succStack);
        vector<int> res;
        if (precStack.size() + succStack.size() < k) return res;
        for (int i = 0; i < k; i++) {
            if (precStack.empty()) {
                res.push_back(succStack.top());
                succStack.pop();
            }
            else if (succStack.empty()) {
                res.push_back(precStack.top());
                precStack.pop();
            }
            else if (fabs((double)precStack.top() - target) <= fabs((double)succStack.top() - target)) {
                res.push_back(precStack.top());
                precStack.pop();
            }
            else {
                res.push_back(succStack.top());
                succStack.pop();
            }
        }
        return res;
    }
private:
    void getPredecessor(TreeNode* root, double target, stack<int>& precStack) {
        if (root == NULL) return;
        getPredecessor(root->left, target, precStack);
        if ((double)root->val > target) return;
        precStack.push(root->val);
        getPredecessor(root->right, target, precStack);
    } 
    void getSuccessor(TreeNode* root, double target, stack<int>& succStack) {
        if (root == NULL) return;
        getSuccessor(root->right, target, succStack);
        if ((double)root->val <= target) return;
        succStack.push(root->val);
        getSuccessor(root->left, target, succStack);
    } 
};
