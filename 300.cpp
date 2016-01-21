/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than 
one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> newnums;
        newnums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int j = upperBound(newnums, nums[i]);
            if (j == 0 || newnums[j - 1] != nums[i]) {
                if (j == newnums.size()) newnums.push_back(nums[i]);
                else newnums[j] = nums[i];
            }
        }
        return newnums.size();
    }
private:
    int upperBound(vector<int>& nums, int target) {
        if (nums[0] > target) return 0;
        if (nums[nums.size() - 1] <= target) return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
