/*
307. Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class SegTreeNode {
public:
    int start;
    int end;
    SegTreeNode* left;
    SegTreeNode* right;
    int sum;
    SegTreeNode(int s, int e): start(s), end(e) {
        sum = 0;
        left = NULL;
        right = NULL;
    }
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        int oldval = sumRange(i, i);
        SegTreeNode* curr = root;
        while(curr) {
            curr->sum += val - oldval;
            int mid = curr->start + (curr->end - curr->start) / 2;
            if (i <= mid) curr = curr->left;
            else curr = curr->right;
        }
    }

    int sumRange(int i, int j) {
        return sumHelper(root, i, j);
    }
private:
    int sumHelper(SegTreeNode* root, int i, int j) {
        if (i == root->start && root->end == j) {
            return root->sum;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (j <= mid) return sumHelper(root->left, i, j);
        else if (i > mid) return sumHelper(root->right, i, j);
        return sumHelper(root->left, i, mid) + sumHelper(root->right, mid + 1, j);
    }
    SegTreeNode* buildTree(vector<int>& nums, int start, int end) {
        SegTreeNode* curr = new SegTreeNode(start, end);
        for (int i = start; i <= end; i++) {
            curr->sum += nums[i];
        }
        if (start < end) {
            int mid = start + (end - start) / 2;
            curr->left = buildTree(nums, start, mid);
            curr->right = buildTree(nums, mid + 1, end);
        }
        return curr;
    }
    SegTreeNode* root;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
