/*
325. Maximum Size Subarray Sum Equals k 
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        vector<int> partial(nums.size(), 0);
        partial[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            partial[i] = partial[i - 1] + nums[i];
        }
        unordered_map<int, int> ht;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (partial[i] == k) {
                res = max(res, i + 1);
            }
            else if (ht.find(partial[i] - k) != ht.end()) {
                res = max(res, i - ht[partial[i] - k]);
            }
            if (ht.find(partial[i]) == ht.end()) {
                ht[partial[i]] = i;
            }
        }
        return res;
    }
};
