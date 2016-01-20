/*
321. Create Maximum Number
Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. Return an array of the k digits. 
You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() && nums2.empty()) return vector<int>();
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;
        for (int i = max(k - m, 0); i <= min(n, k); i++) {
            vector<int> cand = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
            if (greater(cand, 0, res, 0)) res = cand;
        }
        return res;
    }
private:
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> res(k);
        for (int i = 0, j = 0, r = 0; r < k; r++) {
            res[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> res(k);
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while(j > 0 && j + nums.size() - i > k && res[j - 1] < nums[i]) j--;
            if (j < k) res[j++] = nums[i];
        }
        return res;
    }
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++; j++;
        }
        return ((j == nums2.size()) || (i < nums1.size() && nums1[i] > nums2[j]));
    }
};
