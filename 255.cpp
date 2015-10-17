/*
Verify Preorder Sequence in Binary Search Tree
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty() || preorder.size() <= 2) return true;
        int parent = INT_MIN;
        int top = -1;
        for (int i = 0; i < preorder.size(); i++) {
            if (parent > INT_MIN && preorder[i] < parent) return false;
            while (top != -1 && preorder[i] > preorder[top]) {
                parent = preorder[top];
                top--;
            }
            top++;
            preorder[top] = preorder[i];
        }
        return true;
    }
};
