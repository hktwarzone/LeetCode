/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = vector<int>();
            }
            auto it_fw = m.find(nums[i]);
            auto it_bw = make_reverse_iterator(it_fw);
            while(it_fw != m.end() && (long)it_fw->first - nums[i] <= t) {
                if (!it_fw->second.empty()) {
                    auto diff = i - it_fw->second.back();
                    if (diff <= k) return true;
                }
                it_fw++;
            }
            while(it_bw != m.rend() && (long)nums[i] - it_bw->first <= t) {
                if (!it_bw->second.empty()) {
                    auto diff2 = i - it_bw->second.back();
                    if (diff2 <= k) return true;
                }
                it_bw++;
            }
            m[nums[i]].push_back(i);
        }
        return false;
    }
};
