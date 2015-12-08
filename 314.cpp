/*
Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q, next;
        map<int, vector<int>> ht;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            while(!q.empty()) {
                pair<TreeNode*, int> curr = q.front();
                q.pop();
                ht[curr.second].push_back(curr.first->val);
                if (curr.first->left) {
                    next.push(make_pair(curr.first->left, curr.second - 1));
                }
                if (curr.first->right) {
                    next.push(make_pair(curr.first->right, curr.second + 1));
                }
            }
            swap(q, next);
        }
        for (auto it = ht.begin(); it != ht.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
