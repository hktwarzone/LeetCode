/*
164. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int minnum = INT_MAX;
        int maxnum = INT_MIN;
        for (int n : nums) {
            minnum = min(minnum, n);
            maxnum = max(maxnum, n);
        }
        int bucket_size = (maxnum - minnum) / size + 1;
        int bucket_count = (maxnum - minnum) / bucket_size + 1;
        vector<int> max_bucket(bucket_count, INT_MIN);
        vector<int> min_bucket(bucket_count, INT_MAX);
        unordered_set<int> s;
        for (int n : nums) {
            int index = (n - minnum) / bucket_size;
            max_bucket[index] = max(max_bucket[index], n);
            min_bucket[index] = min(min_bucket[index], n);
            s.insert(index);
        }
        int pre = 0;
        int maxgap = 0;
        for (int i = 1; i < bucket_count; i++) {
            if (!s.count(i)) continue;
            maxgap = max(maxgap, min_bucket[i] - max_bucket[pre]);
            pre = i;
        }
        return maxgap;
    }
};
