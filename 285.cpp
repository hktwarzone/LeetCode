/*
Inorder Successor in BST
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->right) {
                curr = node->right;
                while(curr) {
                    st.push(curr);
                    curr = curr->left;
                }
            }
            if (node == p && !st.empty()) return st.top();
        }
        return NULL;
    }
};
