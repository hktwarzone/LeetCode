/*
Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to 
a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 
must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty())  return res;
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
        }
        return res;
    }
};
