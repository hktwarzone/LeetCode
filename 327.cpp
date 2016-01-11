/*
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> partial(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            partial[i + 1] = partial[i] + nums[i];
        }
        return merge(partial, 0, nums.size(), lower, upper);
    }
private:
    int merge(vector<long long>& partial, int start, int end, int lower, int upper) {
        if (end - start <= 0) return 0;
        int mid = start + (end - start) / 2;
        int count = merge(partial, start, mid, lower, upper) + merge(partial, mid + 1, end, lower, upper);
        int j = mid + 1;
        int k = mid + 1;
        int t = mid + 1;
        vector<long long> cache(end - start + 1);
        for (int i = start, r = 0; i <= mid; i++, r++) {
            while(j <= end && partial[j] - partial[i] < lower) j++;
            while(k <= end && partial[k] - partial[i] <= upper) k++;
            while(t <= end && partial[t] < partial[i]) cache[r++] = partial[t++];
            cache[r] = partial[i];
            count += k - j;
        }
        copy(cache.begin(), cache.begin() + t - start, partial.begin() + start);
        return count;
    }
};
